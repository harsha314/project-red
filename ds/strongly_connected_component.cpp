#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

void solve() {};

void dfs(int u, vector<vector<int>>& adj, vector<int>& times, int& timer,
         vector<bool>& vis) {
  if (vis[u]) return;
  for (int v : adj[u]) {
    if (vis[v]) continue;
    vis[v] = true;
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
  for (int u : nodes) {
    if (visited[u]) continue;
    queue<int> que;
    que.push(u);
    while (!que.empty()) {
      int u = que.front();
      components[u] = current;
      que.pop();
      for (int v : rev_adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        que.push(v);
      }
    }
    ++current;
  }
}

int main() {}