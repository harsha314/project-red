#include <iostream>
#include <vector>
#define ll long long

using namespace std;

ll MOD = 998244353;

ll binexp(ll b, ll e) {
  if (e == 0) return 1;
  if (e & 1) {
    return (b * binexp(b, e - 1)) % MOD;
  } else {
    ll result = binexp(b, e >> 1);
    return (result * result) % MOD;
  }
}

class SegmentTree {
 public:
  SegmentTree(int N) {
    tree.resize(N * 4 + 7);
    marked.resize(N * 4 + 7);
    size = N;
  }

 public:
  ll query(int l, int r) { return query(1, 1, size, l, r); }
  void update(int idx, ll V) { update(1, 1, size, idx, V); }
  void update(int l, int r, ll V) { update(1, 1, size, l, r, V); }

 private:
  vector<ll> tree;
  vector<bool> marked;
  int size;

  void push(vector<ll>& t, vector<bool>& marked, int v) {
    if (marked[v]) {
      t[v * 2] = t[v * 2 + 1] = t[v];
      marked[v * 2] = marked[v * 2 + 1] = true;
      marked[v] = false;
    }
  }

  ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
      return tree[v];
    }
    push(tree, marked, v);
    int tm = (tl + tr) / 2;
    return (query(v * 2, tl, tm, l, min(r, tm)) +
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)) %
           MOD;
  }

  void update(int v, int tl, int tr, int pos, ll V) {
    if (tl == tr) {
      tree[v] = V;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v * 2, tl, tm, pos, V);
      else
        update(v * 2 + 1, tm + 1, tr, pos, V);
      tree[v] = (tree[v * 2] + tree[v * 2 + 1]) % MOD;
    }
  }

  // update(1, 1, n, l, r, V)
  void update(int v, int tl, int tr, int l, int r, ll V) {
    if (l > r) return;
    if (l == tl && r == tr) {
      marked[v] = true;
      tree[v] = (tree[v] + V) % MOD;
    } else {
      push(tree, marked, v);

      int tm = (tl + tr) / 2;
      update(v * 2, tl, tm, l, min(r, tm), V);
      update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, V);
    }
  }
};

void solve() {
  int N, M;
  cin >> N >> M;
  vector<ll> A(N);
  SegmentTree tree(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    tree.update(i + 1, A[i]);
  }
  for (int i = 0; i < M; ++i) {
    int L, R;
    cin >> L >> R;
    ll P = tree.query(L, R);
    ll Q = (R - L + 1);
    ll V = (P * binexp(Q, MOD - 2)) % MOD;
    tree.update(L, R, V);
  }
  cout << "\n";
  for (int i = 1; i <= N; ++i) {
    cout << tree.query(i, i) << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case " << t << " : \n";
    solve();
    cout << "\n";
  }
  return 0;
}