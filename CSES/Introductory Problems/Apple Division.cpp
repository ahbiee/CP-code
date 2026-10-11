#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v(25);
int n;

ll dfs(int idx, ll lval, ll rval){
    if(idx >= n) return abs(rval - lval);
    if(idx) return min(dfs(idx+1, lval+v[idx], rval), dfs(idx+1, lval, rval+v[idx]));
    else return dfs(idx+1, lval+v[idx], rval);
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i) cin >> v[i];
    cout << dfs(0, 0, 0) << '\n';
    return 0;
}