#include <iostream>
#include <vector>
#define ll long long

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<vector<int>>& parents,
         vector<bool>& vis, vector<vector<int>>& times, int& timer) {
  if (vis[u]) return;
  times[u][0] = ++timer;
  vis[u] = true;
  for (int i = 1; i < 18; ++i) {
    parents[u][i] = parents[parents[u][i - 1]][i - 1];
  }
  for (int v : adj[u]) {
    if (vis[v]) continue;
    parents[v][0] = u;
    dfs(v, adj, parents, vis, times, timer);
  }
  times[u][1] = ++timer;
}

bool is_ancestor(int u, int v, vector<vector<int>>& times) {
  return times[u][0] <= times[v][0] && times[v][1] <= times[u][1];
}

int lca(int u, int v, vector<vector<int>>& parents,
        vector<vector<int>>& times) {
  if (is_ancestor(u, v, times)) return u;
  if (is_ancestor(v, u, times)) return v;
  for (int i = 17; i >= 0; --i) {
    if (parents[u][i] == 0) continue;
    if (!is_ancestor(parents[u][i], v, times)) u = parents[u][i];
  }
  return parents[u][0];
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
  vector<vector<int>> times(N + 1, vector<int>(2, 0));
  int timer = 0;
  dfs(1, adj, parents, vis, times, timer);
  // for (int i = 1; i <= N; ++i) {
  //   cout << times[i][0] << " " << times[i][1] << "\n";
  //   for (int j = 0; j < 3; ++j) cout << parents[i][j] << " ";
  //   cout << "\n";
  // }
  for (int i = 0; i < Q; ++i) {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v, parents, times) << "\n";
  }
}

int main() {
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}