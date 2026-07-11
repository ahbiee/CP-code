#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<char> v(n);
        int lcnt = 0, rcnt = 0;
        for(int i=0; i<n; ++i){
            cin >> v[i];
            if(v[i] == '(') ++lcnt;
            else ++rcnt;
        }
        if(lcnt != rcnt) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}