#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<int> v(n);
        bool have_zero = false;
        bool can_eliminate = false;
        for(int i=0; i<n; ++i){
            cin >> v[i];
            if(v[i] == 0){
                have_zero = true;
            }
            if(v[i] < n){
                can_eliminate = true;
            }
        }
        if(have_zero || can_eliminate) cout << n << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}