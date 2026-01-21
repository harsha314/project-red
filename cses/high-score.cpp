#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[";
  for (size_t i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) {
      os << ", ";  // Add comma between elements but not after the last one
    }
  }
  os << "]";
  return os;
}

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> edges(M, vector<int>(3, 0));
  ll inf = (1LL << 60) - 1;
  vector<ll> D(N + 1, -inf);
  for (int i = 0; i < M; ++i) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  }
  D[1] = 0;
  for (int i = 1; i < N; ++i) {
    for (vector<int>& edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      if (D[u] != -inf) D[v] = max(D[v], w + D[u]);
    }
    // cout << D << "\n";
  }
  ll ans = D[N];
  vector<int> isInCycle(N + 1, 0);
  vector<vector<int>> revAdj(N + 1);

  for (vector<int>& edge : edges) {
    int u = edge[0], v = edge[1], w = edge[2];
    if (D[u] != -inf && D[v] < D[u] + w) {
      isInCycle[u] = 1;
      isInCycle[v] = 1;
    }
    revAdj[v].push_back(u);
  }

  vector<bool> vis(N + 1, 0);
  queue<int> que;
  que.push(N);
  vis[N];
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (isInCycle[u]) {
      cout << -1 << "\n";
      return;
    }
    for (int v : revAdj[u]) {
      if (!vis[v]) {
        que.push(v);
        vis[v] = 1;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}