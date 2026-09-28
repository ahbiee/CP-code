#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    while(cin >> n >> x){
        vector<int> v(n);
        for(int i=0; i<n; ++i) cin >> v[i];

        vector<int> ans(x+1, 0x3f3f3f3f);
        ans[0] = 0;
        for(int i=1; i<=x; ++i){
            for(int j=0; j<n; ++j){
                if(v[j] <= i) ans[i] = min(ans[i], 1 + ans[i - v[j]]);
            }
        }
        cout << (ans[x] == 0x3f3f3f3f ? -1 : ans[x]) << '\n';
    }
    return 0;
}