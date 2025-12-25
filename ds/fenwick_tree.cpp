#include <iostream>
#include <vector>
#define ll long long

using namespace std;

ll MOD = 1e9 + 7;

// 1-based indexing
class FenwickTree {
 private:
  int size;
  ll* tree;

 public:
  FenwickTree(int size) {
    this->size = size;
    this->tree = new ll[size + 1];
  }
  ll query(int r) {
    ll result = 0;
    for (; r >= 0; r = g(r)) {
      result += tree[r];
    }
    return result;
  }
  ll query(int l, int r) {
    if (l >= r) return 0;
    return query(r) - query(l - 1);
  }

  void update(int idx, ll v) {
    for (; idx < size; idx = f(idx)) {
      tree[idx] = v;
    }
  }

 private:
  int g(int i) { return i & (i + 1); }
  int f(int i) { return i | (i + 1); }
};