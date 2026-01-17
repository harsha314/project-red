#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
  int N, K;
  cin >> N >> K;
  vector<vector<int>> movies(N, vector<int>(2));
  for (int i = 0; i < N; ++i) {
    cin >> movies[i][0] >> movies[i][1];
  }
  sort(movies.begin(), movies.end(), [](vector<int>& m1, vector<int>& m2) {
    if (m1[1] != m2[1])
      return m1[1] < m2[1];
    else
      return m1[0] < m2[0];
  });
  for (int i = 0; i < N; ++i)
    cout << movies[i][0] << " " << movies[i][1] << "\n";
  priority_queue<int, vector<int>, greater<int>> pq;
  int count = K;
  for (int i = 0; i < K; ++i) {
    pq.push(movies[i][1]);
  }
  for (int i = K; i < N; ++i) {
    if (!pq.empty() && pq.top() <= movies[i][0]) {
      pq.pop();
      pq.push(movies[i][1]);
      ++count;
    }
  }
  cout << count << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}