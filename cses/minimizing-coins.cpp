#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int inf = INT32_MAX;

void solve() {
  int N, X;
  cin >> N >> X;
  vector<int> coins(N);
  for (int& x : coins) cin >> x;
  vector<int> dp(X + 1, inf);
  dp[0] = 0;
  for (int i = 1; i <= X; ++i) {
    for (int c : coins) {
      if (c <= i && dp[i - c] != inf) dp[i] = min(dp[i], 1 + dp[i - c]);
    }
  }
  int ans = dp[X];
  if (ans == inf)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}