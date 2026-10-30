// DP
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("1366_in.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    int n, m;
    while(cin >> n >> m && n > 0 && m > 0){
        int a[n+1][m+1], b[n+1][m+1], dp[n+1][m+1];

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(dp, 0, sizeof(dp));

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                cin >> a[i][j];
                a[i][j] += a[i][j-1]; // 上->下 累加和
            }
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                cin >> b[i][j];
                b[i][j] += b[i-1][j]; // 左->右 累加和
            }
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                dp[i][j] = max(dp[i-1][j] + a[i][j], dp[i][j-1] + b[i][j]);
                // [i][j]這裡往上拿，剩下往左看 / 往左拿，剩下往上看
            }
        }
        cout << dp[n][m] << '\n';
    }
    return 0;
}