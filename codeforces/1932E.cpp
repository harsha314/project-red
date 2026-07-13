#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int N;
    cin >> N ;
    string S ;
    cin >> S ;
    vector<int> prefix(N);
    prefix[0] = S[0] - '0';
    for(int i = 1; i < N; ++i) {
        prefix[i] = prefix[i - 1] + (S[i] - '0');
    }
    string result = "";
    int carry = 0;
    for(int i = N - 1; i >= 0; --i) {
        int sum = prefix[i] + carry;
        result += (char)('0' + sum % 10);
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    if(carry > 0)
        result = to_string(carry) + result;
    int i = 0;
    while(i < N && result[i] == '0') {++i;}
    cout << result.substr(i) << "\n";
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