#include <bits/stdc++.h>
#define ll long long 
using namespace std ;
 
const int maxn = 2e5 + 1 ;
vector<ll> t(maxn * 4, INT64_MIN), A(maxn) ;

ll Max(int v, int tl, int tr, int l, int r);
void update(int v, int tl, int tr, int pos, ll new_val);
 
int main(){
    while(true) {
        int ch ;
        cout << "Enter your choice\n" ;
        cin >> ch ;
        if(ch == 0) {
            break;
        } else if (ch == 1) {
            int idx, val ;
            cin >> idx >> val ;
            update(1, 1, maxn, idx, val) ;
        } else if(ch == 2) {
            int l, r;
            cin >> l >> r ;
            cout << Max(1, 1, maxn, l, r) ;
        }
    }
}
 
ll Max(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return INT64_MIN;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(Max(v*2, tl, tm, l, min(r, tm)), Max(v*2+1, tm+1, tr, max(l, tm+1), r));
}
 
void update(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}