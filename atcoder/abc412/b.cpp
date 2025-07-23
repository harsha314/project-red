#include <bits/stdc++.h>
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
  string s;
  string t;
  cin >> s;
  cin >> t;
  int n = s.size(), m = t.size();
  set<char> st;
  for (int i = 0; i < m; ++i) {
    // st.add(t[i]);
    st.insert(t[i]);
  }
  for (int i = 1; i < n; ++i) {
    if ('A' <= s[i] && s[i] <= 'Z') {
      if (st.find(s[i - 1]) == st.end()) {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
}