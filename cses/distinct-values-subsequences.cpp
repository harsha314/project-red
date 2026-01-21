#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
#define ll long long

using namespace std;

ll Z = 1e9 + 7;

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

ll binexp(ll a, ll b) {
  if (b == 0) return 1;
  if (b & 1) {
    ll result = binexp(a, b - 1);
    return (a * result) % Z;
  } else {
    ll result = binexp(a, b >> 1);
    return (result * result) % Z;
  }
}

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int& x : A) cin >> x;
  unordered_map<int, int> frequency;
  ll product = 1;
  ll count = 0;
  for (int i = 0; i < N; ++i) {
    ++frequency[A[i]];
    int f = frequency[A[i]];
    count = (count + (product * binexp(f, Z - 2)) % Z) % Z;
    product = (product * (f + 1)) % Z;
    product = (product * binexp(f, Z - 2)) % Z;
  }
  cout << count << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}