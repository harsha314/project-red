#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  for (int& x : A) cin >> x;
  unordered_map<int, pair<int, int>> prefix;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int remaining = X - A[i] - A[j];
      auto it = prefix.find(remaining);
      if (it != prefix.end()) {
        cout << it->second.first << " " << it->second.second << " ";
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
    }
    for (int j = 0; j < i; ++j) {
      prefix[A[i] + A[j]] = make_pair(j + 1, i + 1);
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