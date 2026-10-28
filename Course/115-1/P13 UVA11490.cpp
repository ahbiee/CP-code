// Math
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 100000007;

int main() {
    ll n;
    while(cin >> n && n){
        bool found = false;
        for(ll y = 1; (n - 6 * y * y) > 0; ++y){
            if((n - 6 * y * y) % (7 * y) == 0){
                ll x = (n - 6 * y * y) / (7 * y) % MOD;
                cout << "Possible Missing Soldiers = " << (2 * x % MOD * x % MOD) % MOD << '\n';
                found = true;
            }
        }
        if(!found) cout << "No Solution Possible\n";
        cout << '\n';
    }
    return 0;
}