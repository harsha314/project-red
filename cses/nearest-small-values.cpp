#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int& x : A) cin >> x;
  stack<int> st;
  for (int i = 0; i < N; ++i) {
    while (!st.empty() && A[st.top()] >= A[i]) {
      int j = st.top();
      st.pop();
    }
    if (st.empty()) {
      cout << 0 << " ";
    } else {
      cout << st.top() + 1 << " ";
    }
    st.push(i);
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}