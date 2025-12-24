#include <iostream>
#include <vector>
#define ll long long

ll MOD = 998244353;

using namespace std;
class SegmentTree {
 public:
  SegmentTree(int N) : size(N) {
    tree.assign(N * 4 + 7, 0);
    lazy.assign(N * 4 + 7, 0);
    marked.assign(N * 4 + 7, false);
  }

  ll query(int l, int r) { return query(1, 1, size, l, r); }
  void update(int l, int r, ll V) { update(1, 1, size, l, r, V); }

 private:
  vector<ll> tree;
  vector<ll> lazy;
  vector<bool> marked;
  int size;

  // Critical fix: Applying value depends on segment length (tr - tl + 1)
  void apply(int v, int tl, int tr, ll V) {
    tree[v] = (V % MOD) * (tr - tl + 1) % MOD;
    lazy[v] = V % MOD;
    marked[v] = true;
  }

  void push(int v, int tl, int tr) {
    if (marked[v]) {
      int tm = (tl + tr) / 2;
      apply(v * 2, tl, tm, lazy[v]);
      apply(v * 2 + 1, tm + 1, tr, lazy[v]);
      marked[v] = false;
      lazy[v] = 0;
    }
  }

  ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return tree[v];

    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return (query(v * 2, tl, tm, l, min(r, tm)) +
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)) %
           MOD;
  }

  void update(int v, int tl, int tr, int l, int r, ll V) {
    if (l > r) return;
    if (l == tl && r == tr) {
      apply(v, tl, tr, V);
    } else {
      push(v, tl, tr);
      int tm = (tl + tr) / 2;
      update(v * 2, tl, tm, l, min(r, tm), V);
      update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, V);
      tree[v] = (tree[v * 2] + tree[v * 2 + 1]) % MOD;  // Pull up
    }
  }
};