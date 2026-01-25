#include <iostream>
#define ll long long

using namespace std;

int Z = 1e9 + 7;

int power(int base, int exponent, int M) {
  if (exponent == 0) return 1;

  if (exponent & 1) {
    ll result = power(base, exponent - 1, M);
    return (result * base) % M;
  } else {
    ll result = power(base, exponent >> 1, M);
    return (result * result) % M;
  }
}

void solve() {
  int A, B, C;
  cin >> A >> B >> C;
  int p = power(B, C, Z - 1);
  cout << power(A, p, Z) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}