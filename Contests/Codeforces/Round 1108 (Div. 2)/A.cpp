#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        for(int i=2; i<=n; i += 2){
            cout << i << ' ' << i-1 << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}