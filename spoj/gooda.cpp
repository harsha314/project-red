#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<int>& times, int& timer,
         vector<bool>& vis) {
  if (vis[u]) return;
  vis[u] = true;
  for (int v : adj[u]) {
    if (vis[v]) continue;
    dfs(v, adj, times, timer, vis);
  }
  times[u] = ++timer;
}

vector<int> strongly_connected_components(int n, vector<vector<int>>& adj) {
  vector<int> times(n, 0);
  vector<bool> visited(n, 0);
  int timer = 0;
  for (int i = 0; i < n; ++i) {
    if (visited[i]) continue;
    dfs(i, adj, times, timer, visited);
  }
  for (int i = 0; i < n; ++i) cout << times[i] << " ";
  cout << "\n";
  vector<int> nodes(n);
  iota(nodes.begin(), nodes.end(), 0);
  sort(nodes.begin(), nodes.end(),
       [&times](int u, int v) { return times[u] >= times[v]; });
  vector<vector<int>> rev_adj(n);
  for (int i = 0; i < n; ++i) {
    for (int v : adj[i]) {
      rev_adj[v].push_back(i);
    }
  }
  vector<int> components(n);
  fill(visited.begin(), visited.end(), 0);
  int current = 1;
  for (int i : nodes) {
    if (visited[i]) continue;
    cout << i << " : ";
    queue<int> que;
    que.push(i);
    visited[i] = true;
    while (!que.empty()) {
      int u = que.front();
      components[u] = current;
      // cout << u << " ";
      que.pop();
      for (int v : rev_adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        que.push(v);
      }
    }
    // cout << "\n";
    ++current;
  }
  return components;
}

void solve() {
  int N, M, S, E;
  cin >> N >> M >> S >> E;
  vector<vector<int>> adj(N);
  --S;
  --E;
  vector<int> F(N);
  for (int i = 0; i < N; ++i) cin >> F[i];
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
  }
  vector<int> components = strongly_connected_components(N, adj);
  int start = components[S], end = components[E];
  vector<ll> component_values(
      accumulate(components.begin(), components.end(), 0));
  for (int i = 0; i < N; ++i) {
    component_values[components[i]] += F[i];
  }
  ll total = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}