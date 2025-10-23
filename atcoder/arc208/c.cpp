// #include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) solve();
}

void solve() {
  int C, X;
  cin >> C >> X;
  int N = (C ^ X);
  ll V = (1ll << 50) + (C - X) / 2;
  if (N > X) {
    cout << N << "\n";
  } else if ((C ^ V) % V == X) {
    cout << V << "\n";
  } else {
    cout << "-1\n";
  }
  // n > x, but n ^ c < n
  // n ^ c = k * n + x, k > 0
}