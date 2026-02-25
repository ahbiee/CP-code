#include <bits/stdc++.h>
#define MOD 100000007
using namespace std;
using ll = long long;
int main() {
    ll S;
    while(~scanf("%lld", &S) && S){
        ll bound = sqrt(S/6+0.2);
        bool found = false;
        for(ll x = 1; x < bound; ++x){
            // formula after logics： y = (S-6x^2)/7x
            ll y = S - 6*x*x;
            if(y <= 0) break; // out of bound, people won't be negative
            if(y % (7*x) == 0){
                found = true;
                ll ans = y / (7*x) % MOD;
                cout << "Possible Missing Soldiers = " << ans*ans*2 % MOD << '\n';
            }
        }
        if(!found) cout << "No Solution Possible\n";
        cout << '\n'; // print a new line anyway
    }
    return 0;
}