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
  int k = (n + 1) * 1024;
  vector<vector<int>> adj(k);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    for (int j = 0; j < 1024; ++j) {
      int u1 = u * 1024 + j;
      int v1 = v * 1024 + (j ^ w);
      adj[u1].push_back(v1);
    }
  }
  vector<int> vis(k, 0);
  int st = 1 * 1024;
  queue<int> que;
  que.push(st);
  vis[st] = 1;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int v : adj[u]) {
      if (!vis[v]) {
        que.push(v);
        vis[v] = 1;
      }
    }
  }
  for (int j = 0; j < 1024; ++j) {
    int idx = n * 1024 + j;
    if (vis[idx]) {
      cout << j << "\n";
      // break;
      return;
    }
  }
  cout << -1 << "\n";
}