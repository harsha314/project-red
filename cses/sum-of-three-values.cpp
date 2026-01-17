#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  for (int& x : A) cin >> x;
  vector<int> id(N);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&A](int a, int b) { return A[a] < A[b]; });
  for (int i = 0; i < N; ++i) {
    int j = i + 1, k = N - 1;
    int target = X - A[id[i]];
    while (j < k) {
      if (A[id[j]] + A[id[k]] < target) {
        ++j;
      } else if (A[id[j]] + A[id[k]] == target) {
        cout << id[i] + 1 << " " << id[j] + 1 << " " << id[k] + 1 << "\n";
        return;
      } else {
        --k;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}