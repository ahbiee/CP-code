#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

bool check(long long mid){
    long long total = 0;
    for(int i=0; i<n; ++i){
        total += mid / v[i];
        if(total >= k) return true;
    }
    return false;
}

int main() {
    while(cin >> n >> k){
        v.resize(n);
        for(int i=0; i<n; ++i) cin >> v[i];
        long long l = 0, r = 1e18;
        long long ans = -1;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if(check(mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}