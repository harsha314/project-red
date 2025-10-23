// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int maxn = 2e5 + 1;
vector<ll> t(maxn * 4, INT64_MIN), A(maxn);

ll query(int v, int tl, int tr, int l, int r);
void update(int v, int tl, int tr, int pos, ll new_val);
void update(int v, int tl, int tr, int l, int r, int add);

int main() {
  while (true) {
    int ch;
    cout << "Enter your choice\n";
    cin >> ch;
    if (ch == 0) {
      break;
    } else if (ch == 1) {
      int idx, val;
      cin >> idx >> val;
      update(1, 1, maxn, idx, val);
    } else if (ch == 2) {
      int l, r;
      cin >> l >> r;
      cout << query(1, 1, maxn, l, r);
    }
  }
}

ll query(int v, int tl, int tr, int l, int r) {
  if (l > r) return INT64_MIN;
  if (l == tl && r == tr) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return query(v * 2, tl, tm, l, min(r, tm)) +
         query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, ll new_val) {
  if (tl == tr) {
    t[v] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, new_val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, new_val);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

// update(1, 1, n, l, r, add)
void update(int v, int tl, int tr, int l, int r, int add) {
  if (l > r) return;
  if (l == tl && r == tr) {
    t[v] += add;
  } else {
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), add);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
  }
}