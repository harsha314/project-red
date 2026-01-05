#include <iostream>
#include <numeric>
#include <vector>
#define ll long long
using namespace std;

// 1-based indexing
class FenwickTree {
 private:
  int size;
  ll* tree;

 public:
  FenwickTree(int size) {
    this->size = size;
    this->tree = new ll[size];
  }
  ll query(int r) {
    ll result = 0;
    for (; r >= 0; r = g(r) - 1) {
      result += tree[r];
    }
    return result;
  }
  ll query(int l, int r) {
    if (l > r) return 0;
    return query(r) - query(l - 1);
  }

  void update(int idx, ll delta) {
    for (; idx < size; idx = f(idx)) {
      tree[idx] += delta;
    }
  }

 private:
  int g(int i) { return i & (i + 1); }
  int f(int i) { return i | (i + 1); }
};

void solve() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; ++i) cin >> P[i];
  vector<int> B(N);
  FenwickTree ft(N + 1);
  for (int i = 1; i <= N; ++i) ft.update(i, 1);
  for (int i = N - 1; i >= 0; --i) {
    int I = P[i];
    int l = 1, r = N;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int count = ft.query(mid);
      if (count > I) {
        r = mid - 1;
      } else if (count == I) {
        B[i] = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    ft.update(B[i], -1);
  }
  for (int i = 0; i < N; ++i) cout << B[i] << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}