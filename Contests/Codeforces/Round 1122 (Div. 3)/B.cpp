#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a > b) cout << a-b+c;
        else if(2*(b-a) < c) cout << a+c-b;
        else cout << b-a;
        cout << "\n";
    }
    return 0;
}