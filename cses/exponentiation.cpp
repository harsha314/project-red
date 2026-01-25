#include <iostream>
#define ll long long

using namespace std;

int Z = 1e9 + 7;

int power(int base, int exponent) {
  if (exponent == 0) return 1;

  if (exponent & 1) {
    ll result = power(base, exponent - 1);
    return (result * base) % Z;
  } else {
    ll result = power(base, exponent >> 1);
    return (result * result) % Z;
  }
}

void solve() {
  int A, B;
  cin >> A >> B;
  cout << power(A, B) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}