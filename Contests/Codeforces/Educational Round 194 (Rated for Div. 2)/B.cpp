#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int x, y;
        ll k;
        cin >> x >> y >> k;
        ll total = 0;
        for(ll i=0; i<k; ++i){
            // cerr << "Current total: " << total << '\n';
            if(y < 2*x){
                total += (k-i) * (y % x);
                break;
            }
            else{
                total += (y++ % x++);
            }
        }
        cout << total << '\n';
    }
    return 0;
}