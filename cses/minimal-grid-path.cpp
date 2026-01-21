#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<string> grid(N);
  for (int i = 0; i < N; ++i) cin >> grid[i];
  int i = 0, j = 0;
  while (i < N && j < N) {
    if (grid[i + 1][j] < grid[i]) }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}