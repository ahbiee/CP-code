#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    while(n--){
        ll a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        if(b <= a && a <= 2*b && (a+b)%3 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}