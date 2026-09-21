#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n >> ws;
        string s;
        cin >> s;

        bool ok = true;
        for(int i=0; i<n; ++i){
            if(s[i-1] > s[i]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "0\n";
            continue;
        }

        int zeros = 0;
        for(char c : s){
            if(c == '0') ++zeros;
        }

        if(s[0] == '1'){
            cout << zeros << "\n";
            continue;
        }

        int L, R;
        for(int i=0; i<n; ++i){
            if(s[i] == '1'){
                L = i;
                break;
            }
        }

        int r_zero = 0;
        for(int i=L; i<n; ++i){
            if(s[i] == '0'){
                R = i;
                ++r_zero;
            }
        }

        int mini = r_zero;
        for(int i=L; i<=R; ++i){
            if(s[i] == '1'){
                ++r_zero;
            }
            else{
                --r_zero;
            }
            mini = min(mini, r_zero);
        }
        cout << mini << '\n';
    }
    return 0;
}