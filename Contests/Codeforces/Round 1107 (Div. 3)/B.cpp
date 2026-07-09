#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int x;
        cin >> x;
        
        int y = 1;
        while(x > 0){
            y *= 10;
            x /= 10;
        }
        cout << y+1 << '\n';
    }
    return 0;
}