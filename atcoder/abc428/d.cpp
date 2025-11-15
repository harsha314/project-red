#include <cmath>
#include <iostream>

#define ll long long

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}

void solve() {
  ll C, D;
  cin >> C >> D;
  int l = ceil(log10(C + 1));
  int r = ceil(log10(C + D + 1));
  ll count = 0;
  for (int n = l; n <= r; ++n) {
    ll p = pow(10, n);
    ll x = sqrt(C * (p + 1) + p - C - 1), y = sqrt(C * p + C);
    count += floor(x) - floor(y);
  }
  cout << count << "\n";
}