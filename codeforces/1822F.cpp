#include <bits/stdc++.h>
#define ll long long

using namespace std;

void dfs1(int N, vector<vector<int>>& adj, int u, vector<bool>& vis, vector<int>& down) {
    if(vis[u])
        return;
    vis[u] = 1;
    down[u] = 0;
    int parent = -1;
    for(int v : adj[u]) {
        if(vis[v]) {
            parent = v;
            continue;
        }
        dfs1(N, adj, v, vis, down);
        down[u] = max(down[u], 1 + down[v]);
    }
}

void dfs2(int N, vector<vector<int>>& adj, int u, vector<bool>& vis, vector<int>& down, vector<int>& up) {
    if(vis[u])
        return;
    vis[u] = 1;
    int parent = -1, hMax = 0;
    for(int v : adj[u]) {
        if(vis[v]) {
            parent = v;
            break;
        }
    }
    if(parent != -1) {
        int pMax = up[parent];
        for(int i = 0; i < adj[parent].size(); ++i) {
            int v = adj[parent][i];
            if(v != u && down[v] < down[parent]) {
                pMax = max(pMax, 1 + down[v]);
            }
        }
        up[u] = 1 + pMax;
    } else {
        up[u] = 0;
    }
    
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs2(N, adj, v, vis, down, up);
        }
        
    }
}

vector<int> farthest_leaves(vector<vector<int>>& adj) {
    int N = adj.size() - 1;
    vector<bool> vis(N + 1, 0);
    vector<int> down(N + 1, 0), up(N + 1, 0);
    dfs1(N, adj, 1, vis, down);
    for(int i = 1; i <= N; ++i) vis[i] = 0;
    dfs2(N, adj, 1, vis, down, up);
    // for(int i = 1; i <= N; ++i) cout << down[i] << " ";
    // cout << "\n";
    // for(int i = 1; i <= N; ++i) cout << up[i] << " ";
    // cout << "\n"; 
    vector<int> leaves(N + 1, 0);
    for(int i = 1; i <= N; ++i) leaves[i] = max(up[i], down[i]);
    return leaves;
}

void solve() {
    ll N, K, C;
    cin >> N >> K >> C;
    vector<vector<int>> adj(N + 1);
    for(int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> D(N + 1, 0);
    vector<bool> vis(N + 1, 0);
    queue<int> que;
    que.push(1);
    vis[1] = 1;
    D[1] = 0;
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        for(int v : adj[u]) {
            if(!vis[v]) {
                que.push(v);
                D[v] = D[u] + 1;
                vis[v] = 1;
            }
        }
    }
    vector<int> leaves(farthest_leaves(adj));
    ll ans = 0;
    for(int i = 1; i <= N; ++i) {
        ans = max(ans, K * leaves[i] - C * D[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}