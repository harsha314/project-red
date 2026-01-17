#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve() {
  int N, X;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  map<long, int> prefix_sum_count;
  prefix_sum_count[0] = 1;
  long prefix_sum = 0;
  long count = 0;
  for (int i = 0; i < N; ++i) {
    prefix_sum = (prefix_sum + A[i]) % N;
    prefix_sum = (prefix_sum + N) % N;
    auto it = prefix_sum_count.find(prefix_sum);
    if (it != prefix_sum_count.end()) {
      count += it->second;
    }
    ++prefix_sum_count[prefix_sum];
  }
  cout << count << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}