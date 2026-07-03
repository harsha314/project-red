#include <bits/stdc++.h>
#define ll long long 

using namespace std; 

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    for(int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    string S;
    cin >> S;
    queue<int> que;
    vector<bool> vis(N, 0);
    vector<int> leaves;

    que.push(0);
    vis[0] = 1;
    int unassigned = 0;

    while(!que.empty()) {
        int u = que.front();
        que.pop();
        if(adj[u].size() == 1 && u != 0) {
            leaves.push_back(u);
        }
        for(int v : adj[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                que.push(v);
                if(S[v] == '?') ++unassigned;
            }
        }
    }

    int count[2] = {0};
    int unassigned_leaves = 0;
    for(int leaf : leaves) {
        // cout << leaf << " ";
        if(S[leaf] == '?')
            ++unassigned_leaves;
        else 
            ++count[S[leaf] - '0'];
    }
    int unassigned_internal = unassigned - unassigned_leaves;
    // cout << "\n";
    // cout << unassigned_leaves << "\n";
    if(S[0] == '?') {
        cout << floor((unassigned_leaves * 1.0 + (count[0] == count[1] ? (unassigned_internal & 1) : 0)) / 2) + max(count[0], count[1]) << "\n";
    } else {
        cout << ceil((unassigned_leaves * 1.0) / 2) + count[1 ^ (S[0] - '0')] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        // cout << "Case : " << (i + 1) << "\n";
        solve();
    }
    return 0;
}