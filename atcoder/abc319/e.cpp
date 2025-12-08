#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
#define ll long long

using namespace std;

void solve();
ll util(ll start_time, vector<int>& P, vector<int>& T, int X, int Y);
ll exit_time(ll entry_time, int n, vector<int>& P);

int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}

void solve() {
  int N, X, Y;
  cin >> N >> X >> Y;
  N -= 1;
  vector<int> P(N), T(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i] >> T[i];
  }
  int l = 1;
  for (int i = 0; i < N; ++i) {
    l = (l * P[i]) / gcd(l, P[i]);
  }
  vector<ll> calculated(l);
  for (int i = 0; i < l; ++i) {
    calculated[i] = util(i, P, T, X, Y);
    // cout << calculated[i] << "\n";
  }
  // cout << "\n";
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int q;
    cin >> q;
    // cout << q << " " << q % l << " ";
    ll ans = calculated[q % l] + (q / l) * l;

    // cout << calculated[q % l] << " ";
    cout << ans << "\n";
  }
}
ll util(ll start_time, vector<int>& P, vector<int>& T, int X, int Y) {
  int N = P.size();
  ll cur = start_time + X;
  // cout << cur << " ";
  for (int i = 0; i < N; ++i) {
    cur = exit_time(cur, i, P);
    cur += T[i];
    // cout << cur << " ";
  }
  // cout << "\n";
  cur += Y;
  return cur;
}
ll exit_time(ll entry_time, int n, vector<int>& P) {
  ll exit = entry_time;
  while (exit % P[n] != 0) {
    ++exit;
  }
  return exit;
}