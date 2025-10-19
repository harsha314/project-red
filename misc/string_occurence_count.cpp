// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int count_of_s_in_t(string &s, string &t);
vector<int> prefix_function(string &s);

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    string t;
    cin >> s >> t;
    cout << count_of_s_in_t(s, t) << "\n";
  }
  return 0;
}

vector<int> prefix_function(string &s) {
  int n = s.size();
  vector<int> pi(n);
  pi[0] = 0;
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  return pi;
}

int count_of_s_in_t(string &s, string &t) {
  s += '#';
  int n = s.size(), m = t.size();
  vector<int> pi = prefix_function(s);
  int prev = 0;
  int count = 0;
  for (int i = 0; i < m; ++i) {
    int j = prev;
    while (j > 0 && s[j] != t[i]) j = pi[j - 1];
    if (s[j] == t[i]) ++j;
    if (j == n) ++count;
    prev = j;
  }
  return count;
}