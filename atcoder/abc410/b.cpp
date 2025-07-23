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
  int n, q;
  cin >> n >> q;
  vector<int> balls(q);
  for (int &x : balls) cin >> x;
  vector<int> box(n + 1, 0);
  vector<int> pos(q, -1);
  for (int i = 0; i < q; ++i) {
    if (balls[i] == 0) {
      int firstMinIdx = 1;
      for (int i = 1; i <= n; ++i) {
        if (box[i] < box[firstMinIdx]) firstMinIdx = i;
      }
      pos[i] = firstMinIdx;
      ++box[firstMinIdx];
    } else {
      pos[i] = balls[i];
      ++box[pos[i]];
    }
  }
  for (int i = 0; i < q; ++i) cout << pos[i] << " ";
  cout << "\n";
}