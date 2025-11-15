#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}

void solve() {
  int n;
  cin >> n;
  vector<vector<ll>> wgt(n, vector<ll>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> wgt[i][j];
    }
  }
  vector<int> X(n);
  for (int& x : X) {
    cin >> x;
    --x;
  }
  int INF = INT32_MAX;
  vector<vector<ll>> dp(n, vector<ll>(n, INF));
  for (int i = 0; i < n; ++i) dp[i][i] = 0;
  vector<ll> result, curr;
  for (int k = n - 1; k >= 0; --k) {
    int x = X[k];

    for (int i = 0; i < n; ++i) dp[i][x] = min(dp[i][x], wgt[i][x]);
    for (int j = 0; j < n; ++j) dp[x][j] = min(dp[x][j], wgt[x][j]);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dp[i][x] != INF && dp[x][j] != INF) {
          dp[i][j] = min(dp[i][j], dp[i][x] + dp[x][j]);
        }
      }
    }
    curr.push_back(x);
    ll total = 0;
    for (int u : curr) {
      for (int v : curr)
        if (dp[u][v] != INF) total += dp[u][v];
    }
    result.push_back(total);
  }
  reverse(result.begin(), result.end());
  for (int i = 0; i < n; ++i) cout << result[i] << " ";
  cout << "\n";
}