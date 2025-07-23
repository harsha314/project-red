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
  // cin >> T;
  scanf("%d", &T);
  while (T--) solve();
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  ll ans = 1ll * n * n + 1;
  for (int i = 0; i < n; ++i) {
    int j = i + 1;
    for (; j < n && a[i] == a[j]; ++j);
    // printf("%lld\n", 1ll * (i + n - j) * a[i]);
    ans = min(ans, 1ll * (i + n - j) * a[i]);
    i = j - 1;
  }
  printf("%lld\n", ans);
}