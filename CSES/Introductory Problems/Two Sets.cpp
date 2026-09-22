#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;
using ll = long long;

int main() {
    ll n;
    while(cin >> n){
        ll total = 0;
        total = n*(n+1) / 2;
        if(total % 2 == 0){
            cout << "YES\n";
            ll cur = 0;
            ll goal = total / 2;
            bool used[n+1];
            int cnt = n;
            memset(used, false, sizeof(used));
            for(int i = n; i > 0; --i){
                if(cur + i <= goal){
                    cur += i;
                    used[i] = true;
                    --cnt;
                }
            }
            cout << cnt << '\n';
            for(int i=1; i<=n; ++i){
                if(!used[i]) cout << i << ' ';
            }
            cout << '\n' << n - cnt << '\n';
            for(int i=1; i<=n; ++i){
                if(used[i]) cout << i << ' ';
            }
            cout << '\n';
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}