#include <iostream>
#include <vector>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) solve();
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), c(n);
  for (int i = 1; i < n; ++i) cin >> c[i];
  for (int i = 1; i < n; ++i) cin >> a[i];
  vector<int> dp(n, n);
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    // if (a[i] > 0) {
    for (int j = i - 1; j >= i - c[i] && j >= 0; --j) {
      if (a[j] > 0 || j == 0) dp[i] = min(dp[i], 1 + dp[j]);
    }
    // } else
    // dp[i] = dp[i - 1];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) ans = max(ans, dp[i]);
  }
  for (int& x : dp) cout << x << " ";
  cout << "\n";
  cout << ans << "\n";
}