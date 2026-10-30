// Math
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll MOD = 1e9+9;

/*
開 ll，MOD
用fastpow 算 (MOD-2)^2 叫 two_inv
答案初始為1，每次讀新數進來 ans *= (1+2*A) % MOD
輸出答案 ((ans-1)*two_inv) % MOD
*/

ll fastpow(ll base, ll p){
    p %= MOD;
    ll ret = 1;
    while(base){
        if(base & 1) ret = (ret * p) % MOD;
        p = p * p % MOD;
        base /= 2LL;
    }
    return ret;
}

int main() {
    freopen("12810_in.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    int kase;
    cin >> kase;
    ll two_inv = fastpow(MOD-2, 2);
    while(kase--){
        int n;
        cin >> n;
        ll ans = 1, A;

        for(int i=0; i<n; ++i){
            cin >> A;
            ans = (ans * (1+2*A)) % MOD;
        }
        ans = ((ans - 1) * two_inv) % MOD;
        cout << ans << '\n';
    }
    return 0;
}