#include <iostream>
#include <vector>

using namespace std;

void printLcs(int N, int M, vector<vector<int>>& dp, int* A, int* B) {
  if (N == 0 || M == 0) {
    return;
  }
  if (A[N - 1] == B[M - 1]) {
    printLcs(N - 1, M - 1, dp, A, B);
    cout << A[N - 1] << " ";
  } else {
    if (dp[N][M - 1] >= dp[N - 1][M])
      printLcs(N, M - 1, dp, A, B);
    else
      printLcs(N - 1, M, dp, A, B);
  }
}

void solve() {
  int N, M;
  cin >> N >> M;
  int A[N], B[M];
  for (int i = 0; i < N; ++i) cin >> A[i];
  for (int i = 0; i < M; ++i) cin >> B[i];
  vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (A[i] == B[j]) {
        dp[i + 1][j + 1] = 1 + dp[i][j];
      } else {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }
  cout << dp[N][M] << "\n";
  printLcs(N, M, dp, A, B);
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}