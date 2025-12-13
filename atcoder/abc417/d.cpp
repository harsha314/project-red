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
  for (int j = 0; j <= R; ++j) {
    if (j <= P[N - 1])
      dp[N - 1][j] = j + A[N - 1];
    else
      dp[N - 1][j] = max(j - B[N - 1], 0);
  }
  for (int i = N - 2; i >= 0; --i) {
    for (int j = 0; j <= R; ++j) {
      if (j <= P[i]) {
        dp[i][j] = dp[i + 1][j + A[i]];
      } else
        dp[i][j] = dp[i + 1][max(j - B[i], 0)];
    }
  }
  // for (int i = 0; i < N; ++i) {
  //   for (int j = 0; j <= R; ++j) cout << dp[i][j] << " ";
  //   cout << "\n";
  // }
  vector<int> prefixB(N);
  prefixB[0] = B[0];
  for (int i = 1; i < N; ++i) prefixB[i] = prefixB[i - 1] + B[i];
  vector<int> prefixMaxP(N);
  prefixMaxP[0] = P[0];
  for (int i = 1; i < N; ++i) prefixMaxP[i] = max(prefixMaxP[i], P[i]);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int X;
    cin >> X;
    // int j = 0;
    // while (X > R && j < N && X > P[j]) {
    //   X -= B[j];
    //   ++j;
    // }
    // if (j < N) {
    //   cout << dp[j][X] << "\n";
    // } else {
    //   cout << X << "\n";
    // }
    if (X < R) {
      cout << dp[0][X] << "\n";
      continue;
    }

    auto it = lower_bound(prefixB.begin(), prefixB.end(), X - R);
  }
}