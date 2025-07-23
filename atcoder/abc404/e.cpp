#include <bits/stdc++.h>
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
  vector<int> a(n - 1), c(n - 1);
  for (int &x : c) cin >> x;
  for (int &x : a) cin >> x;
  vector<int> dp(n - 1, n);
  dp[0] = 1;
  for (int i = 1; i < a.size(); ++i) {
    for (int j = i - 1; j >= i - c[i] && j >= 0; --j) {
      dp[i] = min(dp[i], 1 + dp[j]);
    }
  }
  int ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] > 0) ans = max(ans, dp[i]);
  }
  for (int &x : dp) cout << x << " ";
  cout << ans << "\n";
}