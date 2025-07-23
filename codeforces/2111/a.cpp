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
  scanf("%d", &T);
  while (T--) solve();
}

void solve() {
  int x;
  scanf("%d", &x);
  for (int i = 1; i < 31; ++i) {
    if ((1 << i) - 1 >= x) {
      printf("%d\n", i * 2 + 1);
      break;
    }
  }
}