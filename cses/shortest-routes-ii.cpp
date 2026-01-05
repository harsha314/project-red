#include <iostream>
#include <vector>
#define ll long long

using namespace std;

void solve() {
  int N, M, Q;
  cin >> N >> M >> Q;
  ll inf = 1e9 * N + 1;
  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, inf));
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    dp[u][v] = min(dp[u][v], w * 1ll);
    dp[v][u] = min(dp[v][u], w * 1ll);
  }
  for (int i = 1; i <= N; ++i) dp[i][i] = 0;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      for (int k = 1; k <= N; ++k)
        if (dp[j][i] != -1 && dp[i][k] != -1)
          dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
  for (int i = 0; i < Q; ++i) {
    int a, b;
    cin >> a >> b;
    cout << (dp[a][b] == inf ? -1 : dp[a][b]) << "\n";
  }
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