#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int timer = 0;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& out) {
  if (vis[u]) return;
  ++timer;
  vis[u] = 1;
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(v, adj, vis, out);
    }
  }
  ++timer;
  out[u] = timer;
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
  dfs(0, adj, vis, out);
  vector<int> ids(N);
  for (int i = 0; i < N; ++i) ids[i] = i, vis[i] = 0;
  sort(ids.begin(), ids.end(),
       [&out](int a, int b) { return out[a] < out[b]; });
  int components = 0;
  vector<int> heads;
  for (int i = 0; i < N; ++i) {
    int u = ids[i];
    if (vis[u]) continue;
    queue<int> que;
    que.push(u);
    vis[u] = 1;
    while (!que.empty()) {
      int a = que.front();
      que.pop();
      for (int v : revAdj[a]) {
        if (!vis[v]) {
          que.push(v);
          vis[v] = 1;
        }
      }
    }
    heads.push_back(u);
    ++components;
  }
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