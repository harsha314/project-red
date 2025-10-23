#include <iostream>
#include <vector>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;

ll MOD = 998244353;

void solve();

// fast modular-exponentiation
ll modexp(ll x, ll e = MOD - 2) {
  ll r = 1;
  x %= MOD;
  while (e) {
    if (e & 1) r = (r * x) % MOD;
    x = (x * x) % MOD;
    e >>= 1;
  }
  return r;
}

// Segment-tree node
struct Node {
  ll sum;   // sum of this segment
  ll m, a;  // lazy tag: x -> m*x + a
  Node() : sum(0), m(1), a(0) {}
};

struct SegTree {
  int n;
  vector<Node> st;

  SegTree(int _n) : n(_n) { st.resize(4 * n); }

  // Build initial sums from A[0..n-1]
  void build(int p, int L, int R, const vector<ll>& A) {
    if (L == R) {
      st[p].sum = A[L] % MOD;
    } else {
      int mid = (L + R) >> 1;
      build(p << 1, L, mid, A);
      build(p << 1 | 1, mid + 1, R, A);
      st[p].sum = (st[p << 1].sum + st[p << 1 | 1].sum) % MOD;
    }
  }

  // Apply lazy tag (m2,a2) to node p, of length len
  void apply(int p, int len, ll m2, ll a2) {
    // compose new tag onto existing tag
    // new: x -> m2*(m*x + a) + a2 = (m2*m) * x + (m2*a + a2)
    st[p].m = (st[p].m * m2) % MOD;
    st[p].a = (st[p].a * m2 % MOD + a2) % MOD;
    // update the sum: sum -> m2*sum + a2*len
    st[p].sum = (st[p].sum * m2 % MOD + a2 * (ll)len % MOD) % MOD;
  }

  // Push lazy tags p -> children
  void push(int p, int L, int R) {
    if (st[p].m == 1 && st[p].a == 0) return;
    int mid = (L + R) >> 1;
    int lc = p << 1, rc = p << 1 | 1;
    apply(lc, mid - L + 1, st[p].m, st[p].a);
    apply(rc, R - mid, st[p].m, st[p].a);
    st[p].m = 1;
    st[p].a = 0;
  }

  // Range-update [i..j]: x -> v1*x + v2
  void update(int p, int L, int R, int i, int j, ll v1, ll v2) {
    if (j < L || R < i) return;
    if (i <= L && R <= j) {
      apply(p, R - L + 1, v1, v2);
      return;
    }
    push(p, L, R);
    int mid = (L + R) >> 1;
    update(p << 1, L, mid, i, j, v1, v2);
    update(p << 1 | 1, mid + 1, R, i, j, v1, v2);
    st[p].sum = (st[p << 1].sum + st[p << 1 | 1].sum) % MOD;
  }

  // Point-query final A[idx]
  ll query(int p, int L, int R, int idx) {
    if (L == R) {
      return st[p].sum;
    }
    push(p, L, R);
    int mid = (L + R) >> 1;
    if (idx <= mid)
      return query(p << 1, L, mid, idx);
    else
      return query(p << 1 | 1, mid + 1, R, idx);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}

void solve() {
  int N, M;
  cin >> N >> M;
  vector<ll> A(N);
  for (ll& x : A) cin >> x;
  SegTree st(N);
  st.build(1, 0, N - 1, A);
  for (int i = 0; i < M; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    --l;
    --r;
    ll m = r - l + 1;
    ll mInv = modexp(m, MOD - 2);
    // for (int j = l; j <= r; ++j) {
    //   A[j] = (A[j] * mInv * (m - 1) + mInv * x) % mod;
    // }

    ll v1 = (mInv * (m - 1)) % MOD;
    ll v2 = (mInv * x) % MOD;
    st.update(1, 0, N - 1, l, r, v1, v2);
  }
  for (int i = 0; i < N; ++i) {
    cout << st.query(1, 0, N - 1, i) << " ";
  }
  cout << "\n";
}