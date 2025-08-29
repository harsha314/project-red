#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 6;
int isprimes[maxn + 1];

int main() {
  for (int i = 2; i <= maxn; ++i) isprimes[i] = 1;
  for (int i = 2; i * i <= maxn; ++i) {
    if (isprimes[i]) {
      for (int j = i * 2; j <= maxn; j += i) isprimes[j] = 0;
    }
  }
  vector<int> primes;
  for (int i = 2; i <= maxn; ++i)
    if (isprimes[i]) primes.push_back(i);
  cout << primes.size() << "\n";

  int mx = 0;
  for (int i = 2; i <= maxn; ++i) {
    if (isprimes[i]) continue;
    auto it = lower_bound(primes.begin(), primes.end(), i);
    for (auto it1 = primes.begin(); it1 < it; ++it) {
    }
  }
  // cout << mx << "\n";
  return 0;
}