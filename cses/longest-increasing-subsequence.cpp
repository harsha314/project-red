#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int& x : A) cin >> x;
  vector<int> lis;
  for (int x : A) {
    auto it = lower_bound(lis.begin(), lis.end(), x);
    if (it == lis.end()) {
      lis.push_back(x);
    } else {
      *it = x;
    }
  }
  cout << lis.size() << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}