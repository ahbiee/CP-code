#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; ++i) cin >> v[i];
        
        sort(v.begin(), v.end(), greater<int>());
        if(n == 2){
            printf("%d %d\n", v[0], v[1]);
            continue;
        }

        bool ok = true;
        for(int i=0; i<n-2; ++i){
            if(v[i] % v[i+1] != v[i+2]){
                ok = false;
                break;
            }
        }

        if(ok){
            printf("%d %d\n", v[0], v[1]);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}