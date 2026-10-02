#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, maxi;
    while(cin >> n >> maxi){
        vector<int> w(n+1), v(n+1);
        for(int i=1; i<=n; ++i) cin >> w[i];
        for(int i=1; i<=n; ++i) cin >> v[i];

        /*
        int dp[n+1][maxi+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; ++i){
            for(int j=0; j < h[i] && j <= maxi; ++j) dp[i][j] = dp[i-1][j];
            for(int j=h[i]; j <= maxi; ++j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-h[i]] + s[i]);
        }
        cout << dp[n][maxi] << '\n';
        */

        int dp[maxi + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i)
            for(int j = maxi; j >= w[i]; --j)
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        cout << dp[maxi] << '\n';
    }
    return 0;
}