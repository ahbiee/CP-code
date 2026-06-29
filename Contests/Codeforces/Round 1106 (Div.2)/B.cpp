#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// b <= a && b <= c

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int num;
        cin >> num;
        ll total = 0;
        for(int b=1; b<=num; ++b){
            ll cnt = num/b; // 對於b在此時，只有 num/b 這麼多個倍數
            total += cnt*cnt; // a, c都能自由選擇要哪個倍數，所以是cnt*cnt
        }
        cout << total << '\n';
    }
    return 0;
}