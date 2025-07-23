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
  vector<bool> used(n, 0);
  for (int &x : a) cin >> x;
  multiset<int> mst;
  for (int i = 1; i + 1 < n; ++i) mst.insert(-a[i]);
  int last = a[0], end = a[n - 1];
  int count = 2;
  while (last * 2 < end) {
    int idx = -1;
    auto it = mst.lower_bound(last * -2);
    if (it == mst.end()) {
      cout << -1 << "\n";
      return;
    }
    mst.erase(it);
    // for (int i = 1; i + 1 < n; ++i) {
    //   if (!used[i] && a[i] <= last * 2) {
    //     if (idx != -1) {
    //       if (a[i] > a[idx]) idx = i;
    //     } else
    //       idx = i;
    //   }
    // }
    // if (idx == -1) {
    //   cout << -1 << "\n";
    //   return;
    // }
    // cout << last << "\n";
    // used[idx] = 1;
    // last = a[idx];
    last = -(*it);
    ++count;
  }
  cout << count << "\n";
}