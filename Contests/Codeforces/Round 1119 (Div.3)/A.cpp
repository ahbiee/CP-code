#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cost = 0;
        bool haveZero;
        int st=0;
        while(st < n){
            haveZero = false;
            int tmp = st;
            while(tmp < st+k){
                if(s[tmp] == '0'){
                    haveZero = true;
                    break;
                }
                ++tmp;
            }
            if(!haveZero) ++cost;
            st += k;
        }
        cout << cost << '\n';
    }
    return 0;
}