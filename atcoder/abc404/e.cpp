#include <iostream>
#include <vector>
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
  int n;
  cin >> n;
  vector<int> a(n), c(n);
  for (int i = 1; i < n; ++i) cin >> c[i];
  for (int i = 1; i < n; ++i) cin >> a[i];

  int ans = 0, pre = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > 0) {
      int l = i, r = i;
      while (pre < l) {
        int nl = l;
        for (int j = l; j <= r; ++j) nl = min(nl, j - c[j]);
        r = l;
        l = nl;
        ++ans;
      }
      pre = i;
    }
  }
  cout << ans << "\n";
}