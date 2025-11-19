#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
}

void solve() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int& a : A) cin >> a;
  for (int& b : B) cin >> b;
  if (A == B) {
    cout << "Yes\n";
    return;
  }
  int s1 = accumulate(A.begin(), A.end(), 0);
  int s2 = accumulate(B.begin(), B.end(), 0);
  if (s1 != s2) {
    cout << "No\n";
    return;
  }
  if ((s1 == 1 && (A[0] == 1 || A[N - 1] == 1)) ||
      (s2 == 1 && (B[0] == 1 || B[N - 1] == 1))) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
}