#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll bill(ll use){
    ll ret = 0;
    if(use <= 100) return use*2;
    ret += 100*2;
    if(use <= 10000) return ret + (use-100)*3;
    ret += (10000-100)*3;
    if(use <= 1000000) return ret + (use-10000)*5;
    ret += (1000000-10000)*5;
    return ret + (use-1000000)*7;
}

int main(){
    ll a, b; // a是一起付，b是絕對差值
    while(cin >> a >> b && a){
        ll l=0, r=a, mid;
        ll tmp, total;
        // 第一次二分搜找價格
        while(l <= r){
            mid = l + (r-l)/2;
            tmp = bill(mid);
            if(tmp == a){
                total = mid;
                break;
            }
            if(tmp > a) r = mid-1;
            else l = mid+1;
        }
        // 第二次二分搜找能耗
        l=0, r=total/2;
        ll X, Y;
        while(l <= r){
            mid = l + (r-l)/2;
            X = bill(mid); // 我的(小)
            Y = bill(total-mid); // 鄰居(大)
            ll diff = Y-X;
            if(diff == b){
                printf("%lld\n", X);
                break;
            }
            if(diff > b) l = mid+1;
            else r = mid-1;
        }
    }
    return 0;
}