#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;

struct TrieNode {
  TrieNode *children[26] = {NULL};
};

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}

void solve() {
  string s;
  cin >> s;
  string good;
  cin >> good;
  int k, n = s.size();
  cin >> k;
  TrieNode *head = new TrieNode();
  for (int i = 0; i < n; ++i) {
    int bad_cnt = 0;
    int j = i;
    TrieNode *cur = head;
    for (; j < n; ++j) {
      if (good[s[j] - 'a'] == '0') ++bad_cnt;
      if (bad_cnt > k) break;
      if (cur->children[s[j] - 'a'] == NULL)
        cur->children[s[j] - 'a'] = new TrieNode();
      cur = cur->children[s[j] - 'a'];
    }
  }
  int answer = 0;
  queue<TrieNode *> que;
  que.push(head);
  while (!que.empty()) {
    TrieNode *cur = que.front();
    que.pop();
    ++answer;
    for (int i = 0; i < 26; ++i) {
      if (cur->children[i] != NULL) {
        que.push(cur->children[i]);
      }
    }
  }
  cout << answer - 1 << "\n";
}