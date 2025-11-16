#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases = 1;
    int n, q;
    while(cin >> n >> q){
        if(n == 0 && q == 0) break;
        cout << "CASE# " << cases << ":\n";

        vector<int> arr(n, 0);

        for(int i=0; i<n; ++i) cin >> arr[i];

        sort(arr.begin(), arr.end());

        int x;
        while(q--){
            cin >> x;
            //int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin(); 用algorithm的lower_bound可以省去寫code的時間
            int pos;
            int l = 0, r = arr.size()-1, mid;
            while(l <= r){
                mid = (l+r)/2;
                if(arr[mid] == x){
                    pos = mid;
                    r = mid-1; // 這裡不break，保證在找到目標之後持續壓縮左邊，繼續往左邊找相同的值
                }
                else if(arr[mid] < x){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            if(pos < n && arr[pos] == x) cout << x << " found at " << pos+1; // numbered from 1 to N
            else cout << x << " not found";

            cout << '\n';
        }
        ++cases;
    }

    return 0;
}