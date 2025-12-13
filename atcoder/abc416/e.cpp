#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const ll inf = 1e15;

void solve();

void updateAPSP(vector<vector<ll>>& dp, int x, int y, int z);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, inf));
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    dp[u][v] = dp[v][u] = min(dp[u][v], w * 1ll);
  }

  int K, T;
  cin >> K >> T;
  vector<int> air(K);
  for (int i = 0; i < K; ++i) cin >> air[i];
  for (int i = 0; i < K; ++i) {
    dp[0][air[i]] = 0;
    dp[air[i]][0] = T;
  }
  for (int i = 0; i <= N; ++i) dp[i][i] = 0;
  for (int j = 0; j <= N; ++j)
    for (int i = 0; i <= N; ++i)
      for (int k = 0; k <= N; ++k)
        if (dp[i][j] < inf && dp[j][k] < inf)
          dp[i][k] = min(dp[i][k], dp[i][j] + dp[j][k]);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      ll x, y, t;
      cin >> x >> y >> t;
      updateAPSP(dp, x, y, t);
      updateAPSP(dp, y, x, t);
    } else if (tp == 2) {
      int x;
      cin >> x;
      updateAPSP(dp, 0, x, 0);
      updateAPSP(dp, x, 0, T);
    } else {
      ll f = 0;
      for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
          if (dp[i][j] != inf) f += dp[i][j];
      cout << f << "\n";
    }
  }
}

void updateAPSP(vector<vector<ll>>& dp, int x, int y, int z) {
  ll old = dp[x][y];
  dp[x][y] = min(dp[x][y], z * 1ll);
  if (old == dp[x][y]) return;
  vector<vector<ll>> dp1(dp);
  int N = dp.size() - 1;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      if (dp[i][x] < inf && dp[y][j] < inf)
        dp1[i][j] = min(dp1[i][j], dp[i][x] + z + dp[y][j]);
    }
  }
  dp = dp1;
}