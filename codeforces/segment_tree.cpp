#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;

void solve();
void update(int v, int tl, int tr, int pos, int new_val);
int query(int v, int tl, int tr, int l, int r);
const int MAXN = 100000;
int tree[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}

void solve() {}

void update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr) {
    tree[v] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(2 * v, tl, tm, pos, new_val);
    } else {
      update(2 * v + 1, tm + 1, tr, pos, new_val);
    }
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
  }
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r) return INT_MAX;
  if (l == tl && r == tr) {
    return tree[v];
  }
  int tm = (tl + tr) / 2;
  int left_query = query(2 * v, tl, tm, l, min(r, tm));
  int right_query = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
  return min(left_query, right_query);
}