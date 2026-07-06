#include <bits/stdc++.h>
#define ll long long
using namespace std;

int MAXN = 1e3 + 2;

vector<vector<ll>> T(MAXN + 1, vector<ll>(MAXN + 1));

ll query(int I, int J) {
    ll result = 0;
    for(int i = I; i >= 0; i = (i & (i + 1)) - 1) {
        // cout << i << " ";
        for(int j = J; j >= 0; j = (j & (j + 1)) - 1) {
            result += T[i][j];
        }
    }
    return result;
}

void update(int I, int J, ll delta) {
    for(int i = I; i <= MAXN; i |= (i + 1)) {
        for(int j = J; j <= MAXN; j |= (j + 1)) {
            T[i][j] += delta;
        }
    }
}

void solve() {
    for(int i = 0; i <= MAXN; ++i)
        for(int j = 0; j <= MAXN; ++j)
            T[i][j] = 0;
    int N, Q;
    cin >> N >> Q;
    for(int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        update(X, Y, X * Y);
    }
    for(int i = 0; i < Q; ++i) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        // hs += 1;
        // ws += 1;
        hb -= 1;
        wb -= 1;
        // cout << hs << " " << ws << " " << hb << " " << wb << "\n";
        ll result = query(hb, wb) - query(hb, ws) - query(hs, wb) + query(hs, ws) ;
        // cout << query(hb, wb) << " " << query(hb, ws) << " " << query(hs, wb) << " " << query(hs, ws) << "\n";
        cout << result << "\n";
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}