#include <cstdint>
#include <iostream>
#include <unordered_set>
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
  int N;
  cin >> N;
  vector<int> A(N);
  for (int& x : A) cin >> x;
  int i = 0, j = 0;
  ll count = 0;
  unordered_set<int> window;
  while (i < N) {
    while (j < N && window.find(A[j]) == window.end()) {
      window.insert(A[j]);
      ++j;
    }
    count += j - i;
    window.erase(A[i]);
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