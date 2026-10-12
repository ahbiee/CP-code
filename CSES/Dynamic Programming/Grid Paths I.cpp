#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n >> ws;
    char arr[n][n];
    int dp[n][n];
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
            dp[i][j] = 0;
        }
    }
    
    for(int i=0; i<n; ++i){
        if(arr[i][0] == '*') break;
        dp[i][0] = 1;
    }
    for(int i=0; i<n; ++i){
        if(arr[0][i] == '*') break;
        dp[0][i] = 1;
    }

    for(int i=1; i<n; ++i){
        for(int j=1; j<n; ++j){
            if(arr[i][j] == '.') dp[i][j] = dp[i-1][j]%MOD + dp[i][j-1]%MOD;
            dp[i][j] = dp[i][j] % MOD;
        }
    }
    cout << dp[n-1][n-1] << '\n';
    return 0;
}