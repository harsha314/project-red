#include <iostream>
#include <vector>
#define ll long long

using namespace std;

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
  int N, M;
  cin >> N >> M;
  vector<int> D(N + 1, 0);
  for (int i = 0; i < M; ++i) {
    int U, V;
    cin >> U >> V;
    ++D[U];
    ++D[V];
  }
  ll ans = 0;
  for (int i = 1; i <= N; ++i) {
    ans += N - 1 - (N - 1 - D[i]) % 2;
  }
  ans >>= 1;
  cout << ans << "\n";
}