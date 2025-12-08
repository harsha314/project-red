#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>
#define ll long long

using namespace std;

void solve();
vector<int> minSum(int N, vector<vector<int>>& adj, vector<vector<int>>& wt,
                   vector<int>& Z, int b);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> X(M), Y(M), Z(M);
  for (int i = 0; i < M; ++i) cin >> X[i] >> Y[i] >> Z[i];
  vector<int> A(N);
  vector<vector<int>> adj(N), wt(N);
  vector<unordered_map<int, int>> unqAdj(N);
  for (int i = 0; i < M; ++i) {
    int u = X[i] - 1, v = Y[i] - 1, w = Z[i];
    if (u == v) {
      if (w != 0) {
        cout << "-1\n";
        return;
      }
      continue;
    }
    if (!unqAdj[u].count(v)) {
      adj[u].push_back(v);
      wt[u].push_back(w);
      adj[v].push_back(u);
      wt[v].push_back(w);
      unqAdj[u][v] = adj[u].size() - 1;
      unqAdj[v][u] = adj[v].size() - 1;
    } else {
      int id = unqAdj[u][v];
      if (wt[u][id] != w) {
        cout << "-1\n";
        return;
      }
    }
  }
  for (int i = 0; i < 30; ++i) {
    vector<int> curZ(M);
    for (int j = 0; j < M; ++j) {
      curZ[j] = (Z[j] >> i) & 1;
    }
    vector<int> cur = minSum(N, adj, wt, curZ, i);
    if (cur.size() == 0) {
      cout << "-1\n";
      return;
    }
    for (int j = 0; j < N; ++j) {
      A[j] |= (cur[j] << i);
    }
  }
  for (int i = 0; i < N; ++i) cout << A[i] << " ";
  cout << "\n";
}

vector<int> minSum(int N, vector<vector<int>>& adj, vector<vector<int>>& wt,
                   vector<int>& Z, int b) {
  int M = adj.size();
  vector<int> val(N, -1);
  vector<bool> vis(N, 0);
  for (int i = 0; i < N; ++i) {
    if (vis[i]) continue;
    vector<int> bfs;
    queue<int> que;
    que.push(i);
    vis[i] = true;
    val[i] = 0;
    int count = 0;
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      bfs.push_back(u);
      count += val[u];
      for (int j = 0; j < adj[u].size(); ++j) {
        int v = adj[u][j], w = (wt[u][j] >> b) & 1;
        if (!vis[v]) {
          val[v] = val[u] ^ w;
          vis[v] = true;
          que.push(v);
        } else {
          if (val[v] != val[u] ^ w) return {};
        }
      }
    }
    if (bfs.size() - count < count) {
      for (int u : bfs) val[u] = 1 - val[u];
    }
  }
  return val;
}