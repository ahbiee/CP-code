#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        for(int i=0; i<n; ++i){
            if(i) cout << ' ';
            cout << i*2+1;
        }
        cout << '\n';
    }
    return 0;
}