#include <iostream>
#include <vector>
#define ll long long

using namespace std;

ll Z = 1e9 + 7;

void solve() {
  int N;
  cin >> N;
  vector<int> dp(N + 1);
  dp[0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (j <= i) dp[i] = (dp[i] + dp[i - j]) % Z;
    }
  }
  cout << dp[N] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}