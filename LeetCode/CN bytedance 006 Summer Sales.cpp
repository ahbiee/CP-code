// https://leetcode.cn/problems/tJau2o/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAXT = 100005; // MAX target value
static const int MAXN = 505; // MAX item value

vector<int> cost(MAXN);
vector<ll> happy(MAXN), dp(MAXT);
        

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, target;
    while(cin >> n >> target){
        ll ans = 0;
        fill(dp.begin(), dp.begin() + n + 1, 0);
        int ori, cur, c, h; // a_i, b_i
        int m = 1;
        for(int i=1; i<=n; ++i){
            cin >> ori >> cur >> h;
            c = 2*cur - ori;
            if(c <= 0){ // no need to pay, and can get happy
                target -= c; // - negative = +val
                ans += h; // must choose ones, keep the happy value
            }
            else{
                cost[m] = c; // real cost
                happy[m++] = h; // happy value
            }
        }
        for(int i=1; i<m; ++i){ // item 1 to m (left ones)
            for(int j = target; j >= cost[i]; --j){
                dp[j] = max(dp[j], dp[j - cost[i]] + happy[i]);
            }
        }
        
        cout << ans + dp[target] << '\n';
    }
    return 0;
}

/*
4 100
100 73 60
100 89 35
30 21 30
10 8 10
*/