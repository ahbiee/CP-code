#include <bits/stdc++.h>
using namespace std;

int main() {
    // three situations:
    // odd: after n operations, always be 1
    // even: there are difference between multiple of 4 or not
    // if multiple of four     ... -> 4 -> 2 -> 0 -> 2 -> 0
    // if not multiple of four ... -> 2 -> 0 -> 2 -> 0
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        int tmp;
        int one_cnt = 0, two_cnt = 0, four_cnt = 0;
        for(int i=0; i<n; ++i){
            cin >> tmp;
            if(tmp % 2 == 1) ++one_cnt;
            else if(tmp % 4 == 0) ++four_cnt;
            else ++two_cnt;
        }
        cout << max({one_cnt, two_cnt, four_cnt}) << '\n';
    }

    return 0;
}