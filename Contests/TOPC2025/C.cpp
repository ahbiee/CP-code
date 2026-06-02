#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Tunnel{
    int x, y;
    ll w;
};

int main(){
    int kase;
    scanf(" %d", &kase);
    while(kase--){
        int n, m;
        scanf(" %d%d", &n, &m);
        vector<Tunnel> t(m+1);
        for(int i=1; i<=m; ++i){
            scanf(" %d%d%lld", &t[i].x, &t[i].y, &t[i].w);
        }

        // starts from bottom
        vector<ll> dp(n+1, 0);
        for(int i = m; i > 0; --i){
            int x = t[i].x;
            int y = t[i].y;
            ll w = t[i].w;

            ll next_x = dp[y] + w;
            ll next_y = dp[x] + w;

            dp[x] = next_x;
            dp[y] = next_y;
        }

        ll ans = 0;
        for(int i=1; i<=n; ++i){
            ans = max(ans, dp[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}