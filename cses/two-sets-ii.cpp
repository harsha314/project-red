#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#define ll long long

using namespace std;

ll MOD = 1e9 + 7;

ll binexp(ll a, ll b) {
  if (b == 0) return 1;
  if (b & 1) {
    ll result = binexp(a, b - 1);
    return (result * a) % MOD;
  } else {
    ll result = binexp(a, b >> 1);
    return (result * result) % MOD;
  }
}

void solve() {
  int N;
  cin >> N;
  int total = ((N * (N + 1)) / 2);
  if ((total & 1) == 1) {
    cout << 0 << "\n";
    return;
  }
  total >>= 1;
  vector<int> dp(total + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= N; ++i) {
    vector<int> prev(dp);
    for (int j = i; j <= total; ++j) {
      dp[j] = (dp[j] + prev[j - i]) % MOD;
    }
    // for (int j = 1; j <= total; ++j) cout << dp[j] << " ";
    // cout << "\n";
  }
  cout << (dp[total] * binexp(2, MOD - 2)) % MOD << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}