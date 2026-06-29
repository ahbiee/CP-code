#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a, ll b, ll x){
    if(a == b) return 0;

    if(a < b) swap(a, b); // let a > b

    ll diff = a-b;

    ll ans = min(diff, 1 + solve(a/x, b, x));

    return ans;
}

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        ll a, b, x;
        cin >> a >> b >> x;
        cout << solve(a, b, x) << '\n';
    }
    return 0;
}