#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;
const int MAXN = 1000005;

ll fastpow(ll a, int p){
    ll ret = 1;
    while(p != 0){
        if(p & 1) ret = (ret*a) % MOD;
        a = a*a % MOD;
        p >>= 1;
    }
    return ret;
}

int main() {
    vector<ll> ans(MAXN);
    for(int i=1; i<=MAXN; ++i){
        ans[i] = fastpow(2LL, i);
    }
    int n;
    while(cin >> n){
        cout << ans[n] << '\n';
    }
    return 0;
}