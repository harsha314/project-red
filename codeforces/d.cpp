#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
  int T = 1;
  // cin >> T;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (T--) {
    solve();
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  // cout << n << " " << m << "\n";
  vector<vector<int>> ans(m);
  for (int i = 1; i <= m; ++i) ans[i - 1] = {i};
  for (int i = 2; i <= n; ++i) {
    vector<vector<int>> tmp;
    for (int j = 0; j < ans.size(); ++j) {
      int x = ans[j].size();
      for (int k = ans[j][x - 1] + 10; k <= m - 10 * (n - i); ++k) {
        int last = tmp.size();
        tmp.push_back(ans[j]);
        tmp[last].push_back(k);
      }
    }
    ans = tmp;
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[i].size(); ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}