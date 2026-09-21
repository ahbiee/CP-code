#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    while(cin >> n){
        while(n > 1LL){
            cout << n << ' ';
            if(n % 2LL == 0){ // even
                n /= 2LL;
            }
            else{
                n = 3LL * n + 1LL;
            }
        }
        cout << n << '\n';
    }
    return 0;
}