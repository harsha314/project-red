#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define setbits(x) __builtin_popcountll(x)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sum(x) (accumulate((x).begin(), (x).end(), 0ll))
#define mine(x) (*min_element((x).begin(), (x).end()))
#define maxe(x) (*max_element((x).begin(), (x).end()))

ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;
ll tree[MAXN * 4] = {0};

ll query(int v, int tl, int tr, int l, int r);
void update(int v, int tl, int tr, int pos, ll new_val);
ll binexp(ll a, ll b);

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '[';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << ']';
}

int powerOf2(ll v) {
  if (v == 0) return 0;
  if (v == 1) return 1;
  return 1 + powerOf2(v >> 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a[] = {1, 0, 4, 8, 15, 50};
  for (int v : a) cout << powerOf2(v) << "\n";
}

// 0-based indexing
// call: query(1, 0, n - 1, l, r)
ll query(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) {
    return tree[v];
  }
  int tm = (tl + tr) / 2;
  return max(query(v * 2, tl, tm, l, min(r, tm)),
             query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

// 0-based indexing
// call : update(1, 0, n - 1, pos, new_val)
void update(int v, int tl, int tr, int pos, ll new_val) {
  if (tl == tr) {
    tree[v] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, new_val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, new_val);
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
  }
}

ll binexp(ll a, ll b) {
  if (b == 0) return 1;
  if (b & 1) return (binexp(a, b - 1) * b) % MOD;
  ll res = binexp(a, b >> 1);
  return (res * res) % MOD;
}