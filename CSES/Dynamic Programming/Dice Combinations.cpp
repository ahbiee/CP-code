#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
const int MOD = 1e9+7;

int main() {
    vector<int> dp(MAXN);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < MAXN; ++i){
        for(int j = 1; j <= 6 && j <= i; ++j){
            dp[i] = (dp[i]%MOD + dp[i-j]%MOD)%MOD;
        }
    }
    int n;
    while(cin >> n){
        cout << dp[n] << '\n';
    }
    return 0;
}