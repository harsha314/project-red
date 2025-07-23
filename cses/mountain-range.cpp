#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;

void solve();
void update(int *tree, int v, int tl, int tr, int pos, int new_val);
int mx(int *tree, int v, int tl, int tr, int l, int r);

int main() {
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

void solve() {
  int n;
  cin >> n;
  int h[n];
  for (int i = 0; i < n; ++i) cin >> h[i];
  int next_gt[n];
  int last_gt[n];
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && h[i] >= h[st.top()]) {
      next_gt[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    next_gt[st.top()] = n;
    st.pop();
  }
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && h[i] >= h[st.top()]) {
      last_gt[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    last_gt[st.top()] = -1;
    st.pop();
  }
  int dp[n] = {0};

  int ind[n];
  for (int i = 0; i < n; ++i) ind[i] = i;
  sort(ind, ind + n, [&h](int a, int b) { return h[a] < h[b]; });
  int tree[n * 4 + 1] = {0};
  for (int i = 0; i < n; ++i) {
    int cur = ind[i];
    dp[cur] = 1 + mx(tree, 1, 0, n - 1, last_gt[cur] + 1, next_gt[cur] - 1);
    update(tree, 1, 0, n - 1, cur, dp[cur]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
}

int mx(int *tree, int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) {
    return tree[v];
  }
  int tm = (tl + tr) / 2;
  return max(mx(tree, v * 2, tl, tm, l, min(r, tm)),
             mx(tree, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int *tree, int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr) {
    tree[v] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(tree, v * 2, tl, tm, pos, new_val);
    else
      update(tree, v * 2 + 1, tm + 1, tr, pos, new_val);
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
  }
}