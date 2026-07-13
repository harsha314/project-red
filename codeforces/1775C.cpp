#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ceilLog2(long long n) {
    if (n <= 1) return 0;
    int bits = 0;
    long long temp = n - 1;
    while (temp > 0) {
        bits++;
        temp >>= 1;
    }
    return bits;
}

int floorLog2(long long n) {
    if (n <= 1) return 0;
    int bits = 0;
    long long temp = n;
    while (temp > 1) {
        bits++;
        temp >>= 1;
    }
    return bits;
}

void solve() {
    ll N, X;
    cin >> N >> X;
    if(N < X || (N & X) != X) {
        cout << -1 << "\n";
        return;
    }
    if(N == X) {
        cout << N << "\n";
        return;
    }
    ll n = N, x = X;
    N -= X;
    X = 0;
    bool flag = true;
    int bit = -1;
    for(int i = 60; i >= 0; --i) {
        if(flag) {
            if(((n >> i) & 1) != ((x >> i) & 1)) {
                bit = i;
                flag = false;
            }
        } else {
            if(((x >> i) & 1) == 1) {
                cout << "-1\n";
                return;
            }
        }
    }
    bit = (int)ceil(log2(N));
    // cout << bit << " ";
    ll u = (1ll << ceilLog2(n + 1));
    ll v = (1ll << (1 + floorLog2(N)));
    // cout << u << " " << v << " ";
    ll M = min(v - N + n, u) ;
    if((M & x) != x) {
        cout << "-1\n";
        return;
    }
    cout << M << "\n";
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