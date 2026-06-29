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

        int cur = 0;
        bool noAns = false;
        while(cur < k){
            int ones = 0;
            for(int i=cur; i<n; i+=k){
                if(s[i] == '1') ++ones;
            }
            ++cur;
            if(ones % 2 == 1){
                noAns = true;
                break;
            }
        }
        if(noAns) cout << "No\n";
        else cout << "Yes\n";
    }   
    return 0;
}