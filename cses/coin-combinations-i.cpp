#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
#define ll long long

using namespace std;

int inf = INT32_MAX;
int Z = 1e9 + 7;

void solve() {
  int N, X;
  cin >> N >> X;
  vector<int> coins(N);
  for (int i = 0; i < N; ++i) cin >> coins[i];
  vector<int> dp(X + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= X; ++i) {
    for (int j = 0; j < N; ++j) {
      int c = coins[j];
      if (c <= i && dp[i - c] > 0) dp[i] = (dp[i] + dp[i - c]) % Z;
    }
  }
  cout << dp[X] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}