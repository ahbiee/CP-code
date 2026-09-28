#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll x;
    while(cin >> n >> x){
        vector<ll> v(n);
        for(int i=0; i<n; ++i){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int l = 0, r = v.size() - 1;

        int cnt = 0;
        while(l <= r){
            ++cnt;
            if(l == r) break;

            if(v[l] + v[r] <= x) ++l;
            --r;
        }
        cout << cnt << '\n';
    }
    return 0;
}