#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    int coins = 0;
    int i = 0;
    while(i < N) {
        int j = i + 1;
        int has_two = (A[i] == 2);
        int has_middle_zero = 0;
        while(j < N) {
            if(j - 1 > i && A[j - 1] == 0)
                has_middle_zero = 1;

            if(A[j] == 2)
                has_two = 1;
            int good = (!has_middle_zero && (has_two || A[i] != 0 || A[j] != 0));
            if(!good) {
                break;
            }
            ++j;
        }
        ++coins;
        i = j;
    }
        
    cout << coins << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;;
    // cin >> T;
    for(int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}