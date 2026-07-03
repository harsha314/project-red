#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    vector<int> pos, neg;
    for(int i = 0; i < N; ++i) {
        if(A[i] >= 0)
            pos.push_back(i);
        else
            neg.push_back(i);
    }
    sort(pos.begin(), pos.end(), [&](int id1, int id2) { return A[id1] > A[id2]; });
    sort(neg.begin(), neg.end(), [&](int id1, int id2) { return A[id1] < A[id2]; });
    int i = 0, j = 0;
    int n1 = pos.size(), n2 = neg.size();
    ll sum = 0;

    vector<int> res;
    while(i < n1 && j < n2) {
        while(sum < 0 && i < n1) {
            sum += A[pos[i]];
            res.push_back(pos[i]);
            ++i;
        }
        while(sum >= 0 && j < n2) {
            sum += A[neg[j]];
            res.push_back(neg[j]);
            ++j;
        }
    }
    while(i < n1) {
        res.push_back(pos[i]);
        ++i;
    }
    while(j < n2) {
        res.push_back(neg[j]);
        ++j;
    }
    ll max_sum = INT64_MIN, cur_sum = 0;
    for(int i = 0; i < N; ++i) {
        // cout << A[res[i]] << " ";
        cur_sum += A[res[i]];
        max_sum = max(max_sum, cur_sum);
        if(cur_sum < 0)
            cur_sum = 0;
    }
    // cout << "\n";

    // cout << max_sum << " " ;
    // if(!pos.empty() && !neg.empty())
    //     cout << (A[*pos.begin()] - A[*neg.rbegin()]);
    // cout << "\n";
    if(pos.empty() || neg.empty() || max_sum >= A[*pos.begin()] - A[*neg.begin()]) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for(int i = 0; i < N; ++i) cout << A[res[i]] << " " ;
    cout << "\n";
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