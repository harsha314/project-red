#include <bits/stdc++.h>
using namespace std;

int digits(long long n) {
  int count = 0;
  while (n > 0) {
    ++count;
    n /= 10;
  }
  return count;
}

int main() {
  long long a = 1, b = 1;
  int count = 1;
  int itr = 3;
  while (count < 18) {
    long long c = a + b;
    count = digits(c);
    cout << itr << ' ' << count << "\n";
    a = b;
    b = c;
    ++itr;
  }
  cout << "\n";
  return 0;
}
// 2, 7, 12, 17, 21, 26, 31, 36, 40, 45, 50, 55, 60, 64, 69, 74, 79, 84, 89, 93
//  , 5, 5,   5,  4,  5, 5,   5,  4,  5,  5,  5,  5,  4,  5,  5,  5,  5,