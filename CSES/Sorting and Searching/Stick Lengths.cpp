#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    ll mid = v[n/2];
    ll total = 0LL;
    for(int i=0; i<n; ++i){
        total += abs(v[i] - mid);
    }
    cout << total << '\n';
    return 0;
}