#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll k, ed;
    cin >> n >> k >> ed;
    vector<ll> v(n+1);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    v[n] = ed;
    ll last = 0;
    sort(v.begin(), v.end());

    ll cnt = 0;
    if(v[0] != 0) ++cnt;

    for(int i=0; i<=n; ++i){
        if(v[i] > last){
            cnt += (v[i]-last-1) / k;
            last = v[i];
        }
        if(v[i] == ed) break;
    }
    cout << cnt << '\n';
    return 0;
}