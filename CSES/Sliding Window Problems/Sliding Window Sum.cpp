#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    while(cin >> n >> k){
        ll x, a, b, c; // x_i = (ax_i-1 + b) mod c
        cin >> x >> a >> b >> c;
        vector<ll> v(n);
        v[0] = x;
        for(int i=1; i<n; ++i){
            v[i] = ((a % c) * (v[i-1] % c) + (b % c)) % c;
        }

        ll cur = 0;
        for(int i=0; i<k; ++i) cur += v[i];

        ll ans = cur;
        for(int i=0; i < n - k; ++i){
            cur = cur + v[i+k] - v[i];  
            ans ^= cur;
        }
        cout << ans << '\n';
    }
    return 0;
}