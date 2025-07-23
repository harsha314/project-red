#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a = 0, b = 1;
  long long maxn = 1000000000000000000;
  // long long maxn = 1000000000000;
  int count = 0;
  while (b < maxn) {
    long long c = a + b;
    a = b;
    b = c;
    ++count;
  }
  cout << count << "\n";
  return 0;
}