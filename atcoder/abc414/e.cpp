#include <iostream>
#define ll long long

using namespace std;

ll MOD = 998244353L;

ll sumOfDivisors(ll N);
void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

void solve() {
  ll N;
  cin >> N;
  // cout << N << " ";

  ll term1, term2;

  if (N % 2 == 0) {
    term1 = (N / 2) % MOD;
    term2 = (N + 1) % MOD;
  } else {
    term1 = N % MOD;
    term2 = ((N + 1) / 2) % MOD;
  }
  ll v1 = (term1 * term2) % MOD;

  ll v2 = sumOfDivisors(N) % MOD;
  // cout << v1 << " " << v2 << "\n";
  ll result = (v1 - v2 + MOD) % MOD;
  cout << result << "\n";
}

ll sumOfDivisors(ll N) {
  ll total_sum = 0;
  ll i = 1;
  while (i <= N) {
    ll k = N / i;
    ll j = N / k;
    ll count = j - i + 1;
    total_sum = (total_sum + (k % MOD) * (count % MOD) % MOD) % MOD;
    i = j + 1;
  }
  return total_sum;
}