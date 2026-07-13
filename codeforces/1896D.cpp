#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    set<int> ones;
    for(int i = 0; i < N; ++i) 
        if(A[i] == 1) ones.insert(i);
    for(int i = 0; i < Q; ++i) {
        int ch;
        cin >> ch;
        int num = ones.size();
        if(ch == 1) {
            int s;
            cin >> s;
            if((s - num) & 1) {
                if(num == 0) cout << "NO\n";
                else {
                    int l = *ones.begin(), r = *ones.rbegin();
                    int v1 = r * 2 - (num - 1);
                    int v2 = (N - l - 1) * 2 - (num - 1);
                    if(s <= max(v1, v2)) cout << "YES\n";
                    else cout << "NO\n";
                }
            } else {
                if(2 * N - num >= s) cout << "YES\n";
                else cout << "NO\n";
            }
        } else {
            int idx, v;
            cin >> idx >> v;
            if(v == 1) {
                ones.insert(idx - 1);
            } else {
                ones.erase(idx - 1);
            }
        }
    }
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