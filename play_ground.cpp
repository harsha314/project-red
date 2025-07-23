#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define pii pair<int, int>
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

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}

mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}

void solve(int tc) {
  unordered_multiset<int> mst;
  vector<unordered_multiset<int>::iterator> arr;
  auto it = mst.insert(1);
  arr.push_back(it);
  if (mst.find(1) == mst.end()) {
    cout << "not found";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout << setprecision(15) << fixed;

  int tc = 1;
  cin >> tc;
  cout << tc;
  for (int i = 1; i <= tc; i++) {
    solve(i);
  }

  return 0;
}
