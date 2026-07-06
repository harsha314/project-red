#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; ++i) cin >> A[i] >> B[i];
    ll mn = INT64_MAX;
    ll ans = 0;
    for(int i = 0; i < N; ++i) {
        ll ni = (i + 1) % N;
        ll val = min(A[ni], B[i]);
        mn = min(mn, val);
        ans += A[ni] - val;
    }
    ans += mn;
    cout << ans << "\n";
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