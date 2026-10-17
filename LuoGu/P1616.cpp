#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t, m;
    cin >> t >> m;
    vector<int> cost(m+1), val(m+1);
    for(int i=1; i<=m; ++i){
        cin >> cost[i] >> val[i];
    }
    vector<ll> dp(t+1);

    for(int i = 1; i <= m; ++i){
        for(int j = cost[i]; j <= t; ++j){
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
        }
    }

    cout << dp[t] << '\n';
    return 0;
}