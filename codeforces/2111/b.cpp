#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;

int fib[12] = {0};
void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fib[1] = 1;
  fib[2] = 2;
  for (int i = 3; i <= 11; ++i) fib[i] = (fib[i - 1] + fib[i - 2]);
  int T = 1;
  scanf("%d", &T);
  while (T--) solve();
}

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  string ans = "";
  for (int i = 0; i < m; ++i) {
    int w, l, h;
    scanf("%d%d%d", &w, &l, &h);
    int mn = min(w, l);
    int mx = max(w, l);
    w = mn;
    l = mx;
    // check if nth cube and n-1th cube fit
    // printf("%d %d %d %d %d\n", w, l, h, fib[n], fib[n + 1]);
    if (h >= fib[n] && w >= fib[n] && l >= fib[n + 1]) {
      ans += '1';
    } else if (h >= fib[n + 1] && w >= fib[n]) {
      ans += '1';
    } else {
      ans += '0';
    }
  }
  // printf("%s\n", ans);
  cout << ans << "\n";
}