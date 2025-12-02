#include <iostream>
#include <numeric>
#include <vector>
#define ll long long

ll M;
const ll sum = 5000;

ll K[sum + 1][sum + 1];

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t >> M;
  for (int i = 1; i <= sum; ++i) {
    K[i][0] = 1;
    K[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      K[i][j] = (K[i - 1][j] + K[i - 1][j - 1]) % M;
    }
  }
  while (t--) solve();
}

void solve() {
  int N;
  cin >> N;
  vector<ll> C(N);
  ll total = 0;
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
    total += C[i];
  }

  ll ans = 1, cur = 0;
  for (int i = 0; i < N; ++i) {
    cur += C[i];
    ans = (ans * K[cur][C[i]]) % M;
  }
  cout << ans << "\n";
}
