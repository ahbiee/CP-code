#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n; // total budget m, n items
    while(cin >> m >> n){
        vector<vector<pair<int, int>>> item(n+1);
        int cnt = 0;
        for(int i=1; i<=n; ++i){
            int w, c, b; // weight, cost, belong
            cin >> w >> c >> b;
            item[b].push_back({w, c});
            cnt = max(cnt, b);
        }

        vector<int> dp(m + 1, 0);
        for(int i=1; i<=cnt; ++i){
            if(item[i].empty()) continue;
            for(int j = m; j >= 0; --j){
                for(int k = 0; k < item[i].size(); ++k){
                    if(j >= item[i][k].first) dp[j] = max(dp[j], dp[j - item[i][k].first] + item[i][k].second);
                }
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}