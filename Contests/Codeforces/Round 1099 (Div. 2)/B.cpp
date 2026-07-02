#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<ll> v(n);
        ll diff = 0;
        cin >> v[0];
        for(int i=1; i<n; ++i){
            cin >> v[i];
            diff = max(diff, v[i-1]-v[i]);
        }
        ll prev = -1e18;
        bool cannot = false;
        for(int i=0; i<n; ++i){
            if(v[i] >= prev) prev = v[i];
            else if(v[i] + diff >= prev) prev = v[i]+diff;
            else{
                cannot = true;
                break;
            }
        }
        if(cannot) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}