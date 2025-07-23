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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
  }
  int M = (1 << m);
  int ans = m + n;
  for (int i = 0; i < M; ++i) {
    int e_count = __builtin_popcount(i);
    if (e_count > n) continue;
    // vector<int> deg(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    bool flag = true;
    for (int j = 0; j < m; ++j) {
      if ((i >> j) & 1) {
        int u = edges[j][0], v = edges[j][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        flag &= !(adj[u].size() > 2 || adj[v].size() > 2);
      }
    }
    if (!flag) continue;
    int add = 0, sub = m - e_count;
    vector<bool> vis(n + 1, false);
    int comp = 0;
    for (int j = 1; j <= n; ++j) {
      if (vis[j]) continue;
      queue<int> que;
      que.push(i);
      vis[i] = true;
      int count[3] = {0, 0, 0};
      int nodes = 0;
      while (!que.empty()) {
        int u = que.front();
        que.pop();
        ++count[adj[u].size()];
        ++nodes;
        for (int v : adj[u]) {
          if (!vis[v]) {
            que.push(v);
            vis[v] = true;
          }
        }
      }
      if (count[2] == nodes) continue;
    }
    if (flag) {
      ans = min(ans, sub + add);
    }
  }
  cout << ans << "\n";
}