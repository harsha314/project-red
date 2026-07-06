#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

pii uncommon(vector<int>& p1, vector<int>& p2) {
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    vector<int> intersect;
    set_intersection(p1.begin(), p1.end(), p2.begin(), p2.end(), back_inserter(intersect));
    return {
        accumulate(p1.begin(), p1.end(), 0) - accumulate(intersect.begin(), intersect.end(), 0),
        accumulate(p2.begin(), p2.end(), 0) - accumulate(intersect.begin(), intersect.end(), 0)
    };
}

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> Q(N - 2, vector<int>(3));
    map<pii, set<int>> ids;
    vector<set<int>> adj(N - 2);
    for(int i = 0; i < N - 2; ++i) {
        cin >> Q[i][0] >> Q[i][1] >> Q[i][2];
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                if(j == k)
                    continue;
                ids[{Q[i][j], Q[i][k]}].insert(i);
            }
        }
    }
    for(int i = 0; i < N - 2; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                    if(j == k)
                        continue;
                for(int p : ids[{Q[i][j], Q[i][k]}]) {
                    if(p != i)
                        adj[i].insert(p);
                }
            }
        }
    }
    int start = -1;
    for(int i = 0; i < N - 2; ++i) {
        if(adj[i].size() == 1) {
            start = i;
            // break;
        }
        // cout << adj[i].size() << " ";
    }
    queue<int> que;
    vector<int> vis(N - 2, 0);

    que.push(start);
    vis[start] = 1;

    vector<int> og;
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        // cout << u << " ";
        og.push_back(u);
        for(int v : adj[u]) {
            if(!vis[v]) {
                que.push(v);
                vis[v] = 1;
            }
        }
    }
    // cout << "\n";
    vector<int> P(N);
    for(int i = 0; i + 1 < N - 2; ++i) {
        auto tmp = uncommon(Q[og[i]], Q[og[i + 1]]);
        P[i] = tmp.first;
        P[i + 3] = tmp.second;
        // cout << tmp.first << " " << tmp.second << "\n";
    }
    // cout << accumulate(P.begin(), P.end(), 0) << "\n";
    if(P[N - 3] == 0)
    P[N - 3] = (N * (N + 1)) / 2 - accumulate(P.begin(), P.end(), 0);
    for(int i = 0; i < N; ++i) {
        cout << P[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for(int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}