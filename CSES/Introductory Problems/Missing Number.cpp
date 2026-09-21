#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    ll total;
    while(cin >> n){
        total = 0;
        ll tmp;
        for(int i=0; i<n-1; ++i){
            cin >> tmp;
            total += tmp;
        }
        ll expected = (n+1)*n/2;
        cout << expected - total << '\n';
    }
    return 0;
}