#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<bool> primes_between_l_and_r(ll l, ll r) {
  ll lim = sqrt(r);
  vector<bool> mark(lim + 1, 1);
  vector<ll> primes;
  for (int i = 2; i <= lim; ++i) {
    if (mark[i]) {
      primes.push_back(i);
      for (int j = i * 2; j <= lim; j += i) mark[j] = 0;
    }
  }
  vector<bool> is_prime(r - l + 1, 1);
  for (ll i : primes) {
    for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
      if (l <= j && j <= r) is_prime[j - l] = 1;
  }
  return is_prime;
}

int main() {
  // find prime numbers in the range L..R
  // 1 <= L <= 10^12
  // 1 <= R - L + 1 <= 10^6

  return 0;
}