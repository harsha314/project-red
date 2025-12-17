#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
  map<tuple<int, int, int>, int> slopes;
  map<tuple<int, int>, int> mpCount;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    // for (int j = i + 1; j < N; ++j) {
    //   int dx = X[i] - X[j];
    //   int dy = Y[i] - Y[j];
    //   int s = 1;
    //   if (dx == 0) {
    //     dy = 1;
    //   } else if (dy == 0) {
    //     dx = 1;
    //   } else {
    //     int g = gcd(abs(dx), abs(dy));
    //     s = (abs(dx) / dx) * (abs(dy) / dy);
    //     dx = abs(dx) / g;
    //     dy = abs(dy) / g;
    //   }
    //   auto it = slopes.find(make_tuple(abs(dx), abs(dy), s));
    //   if (it != slopes.end()) {
    //     ans += it->second;
    //   }
    // }
    for (int j = 0; j < i; ++j) {
      int dx = X[i] - X[j];
      int dy = Y[i] - Y[j];
      int s = 1;
      if (dx == 0) {
        dy = 1;
      } else if (dy == 0) {
        dx = 1;
      } else {
        int g = gcd(abs(dx), abs(dy));
        s = (abs(dx) / dx) * (abs(dy) / dy);
        dx = abs(dx) / g;
        dy = abs(dy) / g;
      }
      int mx = (X[i] + X[j]), my = (Y[i] + Y[j]);
      mpCount[make_tuple(mx, my)] += 1;
      slopes[make_tuple(abs(dx), abs(dy), s)] += 1;
    }
  }

  for (auto it : slopes) {
    ans += (it.second * (it.second - 1)) / 2;
  }
  for (auto it : mpCount) {
    ans -= (it.second * (it.second - 1)) / 2;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}