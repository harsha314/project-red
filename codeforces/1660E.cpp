#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for(int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        for(int j = 0; j < N; ++j)
            A[i][j] = S[j] - '0';
    }
    vector<int> cnt(N, 0);
    int total = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0, k = (N - i) % N; j < N; ++j, k = (k + 1) % N) {
            if(A[i][j]) {
                ++cnt[k];
                total += A[i][j];
            }
        }
    }
    int cost = total + N - 2 * (*max_element(cnt.begin(), cnt.end()));
    cout << cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}