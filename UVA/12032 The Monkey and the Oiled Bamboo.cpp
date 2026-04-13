#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    for(int kase = 1; kase <= t; ++kase){
        cin >> n;
        vector<int> v(n+1);
        v[0] = 0;
        for(int i=1; i<=n; ++i) cin >> v[i];
        int maxi = 0, diff;
        for(int i=n; i>0; --i){
            diff = v[i] - v[i-1];
            if(maxi < diff) maxi = diff;
            else if(maxi == diff) maxi = diff+1;
        }
        printf("Case %d: %d\n", kase, maxi);
    }
    return 0;
}