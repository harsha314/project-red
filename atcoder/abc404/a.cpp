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
  while (T--) solve();
}

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int fre[26] = {0};
  for (int i = 0; i < n; ++i) ++fre[s[i] - 'a'];
  for (int i = 0; i < 26; ++i) {
    if (fre[i] == 0) {
      printf("%c\n", (char)('a' + i));
      break;
    }
  }
}