#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<vector<int>>& parents,
         vector<bool>& vis) {
  if (vis[u]) return;
  vis[u] = true;
  for (int i = 1; i < 18; ++i) {
    parents[u][i] = parents[parents[u][i - 1]][i - 1];
  }
  for (int v : adj[u]) {
    if (vis[v]) continue;
    parents[v][0] = u;
    dfs(v, adj, parents, vis);
  }
}

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> parents(N + 1, vector<int>(18));
  vector<vector<int>> adj(N + 1, vector<int>());
  for (int i = 2; i <= N; ++i) {
    int boss;
    cin >> boss;
    adj[boss].push_back(i);
    adj[i].push_back(boss);
  }
  vector<bool> vis(N + 1, 0);
  dfs(1, adj, parents, vis);
  // for (int i = 1; i <= N; ++i) {
  //   for (int j = 0; j < 5; ++j) cout << parents[i][j] << " ";
  //   cout << "\n";
  // }
  for (int i = 0; i < Q; ++i) {
    int x, k;
    cin >> x >> k;
    int id = 0;
    int cur = x;
    while (k > 0) {
      if (k & 1) {
        cur = parents[cur][id];
      }
      k >>= 1;
      ++id;
    }
    cout << (cur == 0 ? -1 : cur) << "\n";
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
}