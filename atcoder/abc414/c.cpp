#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;

int base;

void solve();
ll get_all_palindromes(ll n, ll mx);
bool convert_and_check_palindrome(ll n) {
  string str = "";
  while (n > 0) {
    str += (char)('0' + n % base);
    n /= base;
  }
  int m = str.size();
  for (int i = 0; i * 2 < m; ++i) {
    if (str[i] != str[m - 1 - i]) return false;
  }
  return true;
}
int isPalindrome(ll n) {
  ll rev = 0, t = n;
  while (t > 0) {
    rev = 10 * rev + t % 10;
    t /= 10;
  }
  return rev == n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) solve();
}

void solve() {
  ll n;
  cin >> base >> n;
  ll limit = pow(10, ceil(log10(n) / 2));
  ll sum = 0;
  for (int i = 1; i < 10; ++i) {
    if (i <= n && convert_and_check_palindrome(i)) sum += i;
  }
  for (ll i = 1; i <= limit; ++i) {
    sum += get_all_palindromes(i, n);
  }
  cout << sum << "\n";
}

ll get_all_palindromes(ll n, ll mx) {
  string str_n = to_string(n);
  string rev_n = str_n;
  reverse(rev_n.begin(), rev_n.end());
  ll sum = 0;
  string tmp = str_n + rev_n;
  ll num1 = stoll(tmp);
  if (num1 <= mx && convert_and_check_palindrome(num1)) sum += num1;
  string t = (str_n + (char)('0') + rev_n);
  for (int i = 0; i < 10; ++i) {
    t[str_n.size()] = (char)('0' + i);
    ll num1 = stoll(t);
    if (num1 <= mx && convert_and_check_palindrome(num1)) sum += num1;
  }
  return sum;
}