#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) solve();
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  int st = 0;
  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      int p, x;
      cin >> p >> x;
      int idx = p - 1;
      idx = (idx + st) % n;
      a[idx] = x;
    } else if (type == 2) {
      int p;
      cin >> p;
      int idx = p - 1;
      idx = (idx + st) % n;
      cout << a[idx] << "\n";
    } else {
      int k;
      cin >> k;
      st = (st + k) % n;
    }
  }
}