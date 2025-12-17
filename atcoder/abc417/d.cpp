#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cout << "Case " << t << " : \n";
    solve();
    cout << "\n";
  }
  return 0;
}

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> pab(N, vector<int>(3, 0));
  vector<int> P(N), A(N), B(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i] >> A[i] >> B[i];
  }
  int aMax = *max_element(A.begin(), A.end());
  int pMax = *max_element(P.begin(), P.end());
  int R = aMax + pMax;
  vector<vector<int>> dp(N + 1, vector<int>(R + 1, -1));
  iota(dp[N].begin(), dp[N].end(), 0);
  for (int i = N - 1; i >= 0; --i) {
    for (int j = 0; j <= R; ++j) {
      if (j <= P[i]) {
        dp[i][j] = dp[i + 1][j + A[i]];
      } else
        dp[i][j] = dp[i + 1][max(j - B[i], 0)];
    }
  }
  vector<int> prefixB(N);
  prefixB[0] = B[0];
  for (int i = 1; i < N; ++i) prefixB[i] = prefixB[i - 1] + B[i];
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int X;
    cin >> X;
    if (X <= R) {
      cout << dp[0][X] << "\n";
      continue;
    }
    auto it = lower_bound(prefixB.begin(), prefixB.end(), X - R);
    if (it == prefixB.end()) {
      cout << (X - prefixB.back()) << "\n";
      continue;
    }
    cout << dp[it - begin(prefixB) + 1][X - min(X, *it)] << "\n";
  }
}