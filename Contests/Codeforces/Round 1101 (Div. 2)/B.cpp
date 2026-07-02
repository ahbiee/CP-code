#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<ll> v(n), prefix(n);
        for(int i=0; i<n; ++i){
            cin >> v[i];
            if(i) prefix[i] = prefix[i-1] + v[i];
            else prefix[0] = v[0];
        }
        ll mini = 1e18;
        for(ll i=0; i<n; ++i){
            if(i) cout << ' ';
            mini = min(mini, prefix[i] / (i+1LL));
            cout << mini;
        }
        cout << '\n';
    }
    return 0;
}