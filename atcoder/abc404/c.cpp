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
  // cin >> T;
  while (T--) solve();
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<int> in(n, 0);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
    ++in[u - 1];
    ++in[v - 1];
  }
  if (n != m) {
    cout << "No\n";
    return;
  }
  vector<bool> vis(n, 0);
  queue<int> que;
  que.push(0);
  vis[0] = 1;
  int count = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    ++count;
    for (int v : adj[u]) {
      if (!vis[v]) {
        que.push(v);
        vis[v] = 1;
      }
    }
  }
  if (count != n) {
    cout << "No\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (in[i] != 2) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}