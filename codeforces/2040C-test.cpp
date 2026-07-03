#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i = 0; i < N; ++i) P[i] = i + 1;
    int best = 0;
    do {
        int S = 0;
        for(int i = 0; i < N; ++i) {
            int cur = P[i];
            for(int j = i; j < N; ++j) {
                cur = min(cur, P[j]);
                S += cur;
            }
        }
        best = max(best, S);
        // for(int i = 0; i < N; ++i) cout << P[i] << " ";
        // cout << "\n";
        // cout << "S(P) : " << S << "\n";
    } while(next_permutation(P.begin(), P.end()));

    for(int i = 0; i < N; ++i) P[i] = i + 1;
    do {
        int S = 0;
        for(int i = 0; i < N; ++i) {
            int cur = P[i];
            for(int j = i; j < N; ++j) {
                cur = min(cur, P[j]);
                S += cur;
            }
        }
        if(best == S) {
            for(int i = 0; i < N && (i == N - 1 || P[i] < P[i + 1]); ++i) cout << P[i] << " ";
            cout << "\n";
        }
    } while(next_permutation(P.begin(), P.end()));

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve();
        cout << "\n";
    }
    return 0;
}