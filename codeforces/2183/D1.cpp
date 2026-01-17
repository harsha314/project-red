#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // vector<int> d;
  queue<int> que;
  vector<bool> vis(N, 0);
  que.push(0);
  vis[0] = 1;
  // d.push_back(1);
  int cd = 1;
  while (!que.empty()) {
    int size = que.size();
    for (int i = 0; i < size; ++i) {
      int u = que.front();
      que.pop();
      for (int v : adj[u]) {
        if (!vis[v]) {
          que.push(v);
          vis[v] = true;
        }
      }
    }
    cd = max(cd, (int)que.size());
    // d.push_back(que.size());
  }
  cout << max(cd, 2) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 0; t < T; ++t) solve();
  return 0;
}