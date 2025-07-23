#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;

ll mod = 998244353;

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
    // cout << "-----\n";
  }
}

void solve() {
  ll n, k;
  cin >> n >> k;
  k = min(k, n - k);
  ll lim = sqrt(n);
  vector<bool> primes(lim + 1, 1);
  for (int i = 2; i <= lim; ++i) {
    if (primes[i]) {
      for (int j = i * 2; j <= lim; j += i) primes[j] = 0;
    }
  }
  int offset = n - k + 1;
  vector<ll> nums(k);
  for (int i = 0; i < k; ++i) nums[i] = offset + i;
  ll ans = 1;
  for (int i = 2; i <= lim; ++i) {
    if (primes[i]) {
      int count = 0;
      for (ll j = i; j <= k; j += i) {
        for (ll tmp = j; tmp % i == 0; ++count, tmp /= i);
      }
      for (ll j = ceil((offset * 1.0) / i) * i; j <= n; j += i) {
        if (j - offset >= 0) {
          for (; nums[j - offset] % i == 0; ++count, nums[j - offset] /= i);
        }
      }
      ans = (ans * (1 + count)) % mod;
    }
  }
  // for (int i = 0; i < k; ++i) cout << nums[i] << " ";
  // cout << "\n";
  for (int i = 0; i < k; ++i)
    if (nums[i] > 1) ans = (ans * 2) % mod;
  cout << ans << "\n";
}