#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;

ll MOD = 1e9 + 7;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> G(M + 1);
    G[0] = 1;
    G[1] = 1;

    for(int j = 2; j <= M; ++j) {
        G[j] = (G[j - 1] + G[j - 2]) % MOD ;
    }

    vector<vector<int>> F(N + 1, vector<int>(M + 1));

    for(int j = 1; j <= M; ++j)
        F[0][j] = 1;

    for(int i = 1; i <= N; ++i) {
        F[i][0] = 1;
        F[i][M] = F[i - 1][M];
        if(i >= 2)
            F[i][M] = (F[i][M] + (1ll * F[i - 2][M] * G[M]) % MOD) % MOD;
    }
    cout << F[N][M] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}