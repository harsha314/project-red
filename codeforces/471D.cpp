#include <iostream>
#include <vector>

using namespace std;
void solve(vector<int> &a, vector<int> &b);
vector<int> prefix_function(vector<int> &v);

int main() {
  int t = 1;
  // cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    solve(b, a);
  }
  return 0;
}

void solve(vector<int> &a, vector<int> &b) {
  int n = a.size(), m = b.size();
  if (n == 1) {
    cout << m << "\n";
    return;
  }
  if (n > m) {
    cout << 0 << "\n";
    return;
  }
  vector<int> c(n);
  for (int i = 0; i + 1 < n; ++i) c[i] = a[i + 1] - a[i];
  c[n - 1] = INT32_MIN;
  vector<int> d(m - 1);
  for (int i = 0; i + 1 < m; ++i) d[i] = b[i + 1] - b[i];
  // for (int i : c) cout << i << " ";
  // cout << "\n";
  // for (int i : d) cout << i << " ";
  // cout << "\n";
  vector<int> pi = prefix_function(c);
  int prev = 0;
  int count = 0;
  for (int i = 0; i + 1 < m; ++i) {
    int j = prev;
    while (j > 0 && c[j] != d[i]) j = pi[j - 1];
    if (c[j] == d[i]) ++j;
    // cout << i << " " << j << "\n";
    if (j == n - 1) ++count;
    prev = j;
  }
  cout << count << "\n";
}

vector<int> prefix_function(vector<int> &v) {
  int n = v.size();
  vector<int> pi(n);
  pi[0] = 0;
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && v[i] != v[j]) j = pi[j - 1];
    if (v[i] == v[j]) ++j;
    pi[i] = j;
  }
  return pi;
}