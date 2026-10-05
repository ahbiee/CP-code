#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6+5;
const ll MOD = 1e9+7;
ll dp[MAXN];

int main() {
    int n, k;
    while(cin >> n >> k){
        for(int i=1; i<=k; ++i) dp[i] = 0;
        dp[0] = 1;
        int coins[n];
        for(int i=0; i<n; ++i) cin >> coins[i];

        for(int i=1; i<=k; ++i){
            for(int j=0; j<n; ++j){
                if(i >= coins[j]) dp[i] = (dp[i] + dp[i-coins[j]]) % MOD;
        
        }
        cout << dp[k] << '\n';
    }
    return 0;
}