#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int a, b;
        cin >> a >> b;
        if(a % b == 0) cout << "YEs\n";
        else cout << "No\n";
    }
    return 0;
}