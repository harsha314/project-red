#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int& x : A) cin >> x;
  long count = 0;
  int i = 0, j = 0;
  unordered_map<int, int> frequency;
  while (i < N) {
    while (j < N && frequency.size() <= K) {
      if (frequency.size() == K && frequency.find(A[j]) == frequency.end()) {
        break;
      }
      ++frequency[A[j]];
      ++j;
    }
    count += j - i;
    auto it = frequency.find(A[i]);
    if (it->second == 1) {
      frequency.erase(A[i]);
    } else {
      --it->second;
    }
    ++i;
  }
  cout << count << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
