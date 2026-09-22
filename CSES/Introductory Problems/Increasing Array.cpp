#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    ll total = 0;
    for(int i=1; i<n; ++i){
        if(v[i] < v[i-1]){
            ll diff = v[i-1] - v[i];
            total += diff;
            v[i] = v[i-1];
        }
    }
    cout << total << '\n';
    return 0;
}