#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        int maxi = 0, mini = 0x3f3f3f3f;
        int tmp;
        for(int i=0; i<n; ++i){
            cin >> tmp;
            maxi = max(maxi, tmp);
            mini = min(mini, tmp);
        }
        cout << maxi-mini+1 << '\n';
    }
    return 0;
}