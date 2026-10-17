#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<ll> dp(30005, 0);
    vector<int> coins = {1, 5, 10, 25, 50};
    dp[0] = 1;
    for(int coin : coins){
        for(int j = coin; j <= 30003; ++j){
            dp[j] += dp[j - coin];
        }
    }

    int n;
    cin >> n;
    while(n--){
        int query;
        cin >> query;
        cout << dp[query] << '\n';
    }
    return 0;
}