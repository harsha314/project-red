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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  int k;
  cin >> k;
  int ans = 0;
  for (int x : a) {
    // cout << x << " " << k << "\n";
    if (x >= k) ++ans;
  }
  cout << ans << "\n";
}