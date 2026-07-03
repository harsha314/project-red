#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> util(ll N, ll K) {
    set<int, greater<int>> unused;
    for(int i = 0; i < N; ++i) unused.insert(i + 1);

    vector<int> P;

    ll l = 1, r = (1ll << (N - 1));
    int i = 1;
    while(l < r) {
        // cout << l << " " << r << "\n";
        ll mid = (l + r) >> 1;
        if(mid >= K) {
            P.push_back(i);
            unused.erase(i);
            r = mid;
        } else {
            l = mid + 1;
        }
        ++i;
    }


    while(!unused.empty()) {
        P.push_back(*unused.begin());
        unused.erase(unused.begin());
    }

    return P;
}

void solve() {
    ll N, K;
    cin >> N >> K;

    if(ceil(log2(K)) > N - 1) {
        cout << -1 << "\n";
        return;
    }

    if(N <= 60) {
        vector<int> P(util(N, K));
        for(int v : P) { cout << v << " "; }
        cout << "\n";
        return;
    }

    int M = 60;
    vector<int> T(util(M, K)) ;

    vector<int> P;
    for(int i = 0; i < N - M; ++i) P.push_back(i + 1);
    for(int i = 0; i < M; ++i) P.push_back(T[i] + N - M);

    for(int v : P) { cout << v << " "; }
    cout << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}