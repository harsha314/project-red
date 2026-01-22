#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int timer = 0;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis,
         vector<int>& components) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(v, adj, vis, components);
    }
  }
  components.push_back(u);
}

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N), revAdj(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    revAdj[v].push_back(u);
  }
  vector<int> out(N);
  vector<bool> vis(N, 0);
  timer = 0;
  for (int i = 0; i < N; ++i) {
    if (!vis[i]) dfs(i, adj, vis, out);
  }
  reverse(out.begin(), out.end());
  fill(vis.begin(), vis.end(), 0);
  vector<int> heads;
  for (int i = 0; i < N; ++i) {
    if (vis[out[i]]) continue;
    vector<int> comp;
    dfs(out[i], revAdj, vis, comp);
    heads.push_back(comp[0]);
  }
  int components = heads.size();
  if (components == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
    cout << (heads[1] + 1) << " " << (heads[0] + 1) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}