#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;

void solve();
vector<string> rotate90(vector<string> &s);
int countDiff(vector<string> &s, vector<string> &t);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}

void solve() {
  int n;
  cin >> n;
  vector<string> s(n), t(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i) cin >> t[i];
  vector<string> t1(rotate90(s));
  vector<string> t2(rotate90(t1));
  vector<string> t3(rotate90(t2));
  int count = min({countDiff(s, t), countDiff(t1, t) + 1, countDiff(t2, t) + 2,
                   countDiff(t3, t) + 3});
  printf("%d\n", count);
}

vector<string> rotate90(vector<string> &s) {
  int n = s.size();
  vector<string> res(n, "");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      res[i] += s[n - 1 - j][i];
    }
  }
  return res;
}

int countDiff(vector<string> &s, vector<string> &t) {
  int n = s.size();
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) count += (s[i][j] != t[i][j]);
  }
  return count;
}