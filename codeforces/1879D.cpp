#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    ll ans = 0;
    for(int bit = 0; bit < 30; ++bit) {
        ll prefix = 0;
        ll odd = 0, even = 0;
        ll oddCount = 0, evenCount = 1;
        ll sum = 0;
        for(int i = 1; i <= N; ++i) {
            prefix ^= ((A[i - 1] >> bit) & 1);
            if(prefix == 0) {
                sum = (sum + (oddCount * i) % MOD - odd + MOD) % MOD;
                evenCount++;
                even += i;
            } else {
                sum = (sum + (evenCount * i) % MOD - even + MOD) % MOD;
                oddCount++;
                odd += i;
            }
            // cout << prefix << " " << sum << " ";
            // cout << oddCount << " " << odd << " ";
            // cout << evenCount << " " << even << "\n";
        }
        ans = (ans + ((1ll << bit) * sum) % MOD + MOD) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for(int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}