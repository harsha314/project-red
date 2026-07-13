#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N + 1);
    for(int i = 1; i <= N; ++i) cin >> A[i];
    set<ll> used, not_used;
    vector<ll> ans;

    for(int i = 1; i <= N; ++i) {
        A[i] += i;
        if(!used.count(A[i])) {
            not_used.insert(A[i]);
        }
        ll cur = *(--not_used.upper_bound(A[i]));
        not_used.erase(cur);
        ans.push_back(cur);
        used.insert(cur);
        if(!used.count(cur - 1)) {
            not_used.insert(cur - 1);
        }
    }
    sort(ans.rbegin(), ans.rend());
    for(auto i : ans) {
        cout << i << " ";
    }
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