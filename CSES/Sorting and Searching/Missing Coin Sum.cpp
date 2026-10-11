#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    ll total = 0LL;
    bool found = false;
    for(int i=0; i<n; ++i){
        if(total + 1LL < v[i]){
            found = true;
            break;
        }
        total += v[i];
    }
    cout << total + 1LL << '\n';
    return 0;
}