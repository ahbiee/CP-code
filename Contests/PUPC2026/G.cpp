#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];

    vector<ll> pre(n), suf(n);
    pre[0] = v[0];
    for(int i=1; i<n; ++i) pre[i] = __gcd(v[i], pre[i-1]);
    suf[0] = v[n-1];
    for(int i=1; i<n; ++i) suf[i] = __gcd(v[n-1-i], suf[i-1]);
    
    while(q--){
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        if(l == 0 && r == n-1){
            cout << "0\n";
        }
        else if(l == 0){
            cout << suf[r+1] << '\n';
        }
        else if(r == n-1){
            cout << pre[l-1] << '\n';
        }
        else{
            cout << __gcd(pre[l-1], suf[r+1]) << '\n';
        }
    }
    return 0;
}