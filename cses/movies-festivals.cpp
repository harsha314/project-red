#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int N;
  cin >> N;
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
  int count = 1, cur = movies[0][1];
  for (int i = 1; i < N; ++i) {
    if (cur <= movies[i][0]) {
      ++count;
      cur = movies[i][1];
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