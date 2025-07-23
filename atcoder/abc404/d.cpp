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
  int n, m;
  cin >> n >> m;
  vector<int> costs(n);
  for (int &x : costs) cin >> x;
  vector<vector<int>> anm(m);
  vector<vector<int>> zoo_det(n + 1);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int zoo;
      cin >> zoo;
      anm[i].push_back(zoo);
      zoo_det[zoo].push_back(i);
    }
  }
  ll ans = 1e9 * 2 * 10;
  for (int i = 1; i < pow(3, n); ++i) {
    int t = i;
    ll cur_cost = 0;
    vector<int> seen(m, 0);
    for (int j = 0; j < n; ++j) {
      int digit = t % 3;
      cur_cost += 1ll * digit * costs[j];
      for (int animal : zoo_det[j + 1]) {
        seen[animal] += digit;
      }
      t /= 3;
    }
    bool flag = true;
    for (int j = 0; j < m; ++j)
      if (seen[j] < 2) flag = false;
    if (flag) ans = min(ans, cur_cost);
  }
  cout << ans << "\n";
}