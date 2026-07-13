#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    if(K == 1) {
        cout << S << "\n";
        return;
    }

    string last = "";
    last += S[K - 1];
    if(S[0] == S[K - 1]) {
        if(S[K] != S[N - 1]) {
            int i = K;
            while(i < N) {
                last += S[i];
                ++i;
            }
        } else {
            for(int i = 0; i < ceil((1.0 * (N - K)) / K); ++i) last += S[K];
        }
    }

    // while(i < N && (i + K - 1 < N && S[i + K - 2] == S[i + K - 1])) {
    //     last += S[i + K - 1];
    //     i += K;
    // }
    // while(i < N) {
    //     if(i + K - 1 < N)
    //         last += S[i];
    //     i += K;
    // }
    cout << last << "\n";
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