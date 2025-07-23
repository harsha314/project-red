#include <bits/stdc++.h>
using namespace std;

void solve();

typedef long long ll;

ll m = 1e9 + 7;

ll binexp(ll a, ll b) {
  if (b == 0) return 1;
  if (b & 1) {
    int r = (1ll * binexp(a, b - 1) * a) % m;
    return r;
  } else {
    ll r = binexp(a, b >> 1);
    return (r * r) % m;
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}

void solve() {
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  int prefix[n + 1] = {0};
  prefix[1] = 0;
  int last = 0;
  for (int i = 1; i < n; ++i) {
    //
    // if (s[i] == '0') last = i;
  }
  cout << binexp(2, m - 2) << "\n";
}