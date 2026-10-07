#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n, x;
    while(cin >> n >> x){
        int coins[n];
        for(int i=0; i<n; ++i) cin >> coins[i];
        int dp[x+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; // 得到0元的方法數為1
        for(int i=0; i<n; ++i){
            for(int j=coins[i]; j <= x; ++j){
                dp[j] = (dp[j] + dp[j-coins[i]]) % MOD;
            }
        }
        cout << dp[x] << '\n';
    }
    return 0;
}