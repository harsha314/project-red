#include <bits/stdc++.h>
using namespace std;

struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);

    if (hash1 != hash2) {
      return hash1 ^ hash2;
    }

    // If hash1 == hash2, their XOR is zero.
    return hash1;
  }
};

int main() {
  unordered_map<pair<int, int>, bool, hash_pair> ump;
  ump.insert({make_pair(0, 0), true});
  ump[make_pair(0, 0)] = false;
  return 0;
}