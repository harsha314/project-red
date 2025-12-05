#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void solve();
void merge(vector<int>& parents, vector<int>& counts, int a, int b);
int findParent(vector<int>& parents, int u);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N + 1);
  vector<vector<int>> edges(M), edges1(M);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges[i] = {max(u, v), min(u, v)};
    edges1[i] = {min(u, v), max(u, v)};
  }
  // for (auto& edge : edges) cout << edge[0] << " " << edge[1] << "\n";
  vector<int> parents(N + 1), counts(N + 1, 1);
  for (int i = 1; i <= N; ++i) parents[i] = i;
  sort(edges.begin(), edges.end());
  sort(edges1.begin(), edges1.end());
  vector<int> ans(N + 1, -1);
  unordered_set<int> visited;

  int j = 0, j1 = 0;
  visited.insert(1);
  while (j1 < M && edges1[j1][0] == 1) {
    // merge(parents, counts, edges[j][0], edges[j][1]);
    visited.insert(edges1[j1][1]);
    ++j1;
  }
  ans[1] = visited.size() - 1;

  for (int i = 2; i <= N; ++i) {
    while (j < M && edges[j][0] <= i) {
      merge(parents, counts, edges[j][0], edges[j][1]);
      ++j;
    }

    int p1 = findParent(parents, 1), p2 = findParent(parents, i);
    if (p1 == p2 && counts[p1] == i) {
      while (j1 < M && edges1[j1][0] <= i) {
        visited.insert(edges1[j1][0]);
        visited.insert(edges1[j1][1]);
        ++j1;
      }
      ans[i] = visited.size() - i;
    } else
      ans[i] = -1;
  }
  for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
  cout << "\n";
}

void merge(vector<int>& parents, vector<int>& counts, int a, int b) {
  int p1 = findParent(parents, a), p2 = findParent(parents, b);
  if (p1 == p2) return;
  if (counts[p1] <= counts[p2]) {
    parents[p1] = p2;
    counts[p2] += counts[p1];
  } else {
    parents[p2] = p1;
    counts[p1] += counts[p2];
  }
}

int findParent(vector<int>& parents, int u) {
  if (parents[u] == u) return u;
  return findParent(parents, parents[u]);
}