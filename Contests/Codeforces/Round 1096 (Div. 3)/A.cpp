#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int x, y;
        cin >> x >> y;
        if(x % 2 == 1 && y % 2 == 1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}