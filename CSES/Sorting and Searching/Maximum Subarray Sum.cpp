#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v;

ll kadane(){
    ll best = -1e18, cur = 0;
    for(ll x : v){
        cur = max(x, cur+x);
        best = max(best, cur);
    }
    return best;
}

int main() {
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    cout << kadane() << '\n';
    return 0;
}