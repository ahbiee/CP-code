#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> tmp(n), ans();
    for(int i=0; i<n; ++i){
        cin >> tmp[i];
        for(int j=0; j<=i; ++j) ans.push_back(tmp[j]);
    }
    vector<ll> pre(ans.size()+1);
    pre[0] = 0;;
    for(int i=1; i<=ans.size(); ++i){
        pre[i] = pre[i-1] + ans[i-1];
    }

    int l, r;
    for(int i=0; i<q; ++i){
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << '\n';
    }
    return 0;
}