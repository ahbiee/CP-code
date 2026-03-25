#include <bits/stdc++.h>
using namespace std;

int main(){
    int kase;
    cin >> kase;
    int n;
    while(kase--){
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; ++i) cin >> v[i];
        map<int, int> mp; // 數值 -> 最後出現位置
        int cur;
        int max_len = 0;
        for(int r=0, l=0; r<n; ++r){
            cur = v[r];
            if(mp.count(cur) && mp[cur] >= l){
                l = mp[cur]+1;
            }
            mp[cur] = r;
            max_len = max(max_len, r-l+1);
        }
        cout << max_len << '\n';
    }
    return 0;
}