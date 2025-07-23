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
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(m);
  for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
  sort(a.begin(), a.end());
  // for (int i = 0; i < m; ++i) printf("%d ", a[i]);
  // printf("\n");
  vector<vector<int>> b(n, vector<int>(6));
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < 6; ++j) {
      if (j & 1) {
        b[i][j] = a[m - 1 - i / 2];
        if (i < n - 1) b[i + 1][j] = a[i / 2];
      } else {
        b[i][j] = a[i / 2];
        if (i < n - 1) b[i + 1][j] = a[m - 1 - i / 2];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 6; ++j) printf("%d ", b[i][j]);
    printf("\n");
  }
}