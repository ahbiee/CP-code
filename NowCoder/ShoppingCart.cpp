#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m){
        vector<int> cost(m+1, 0), val(m+1, 0), f(m+1, 0);
        vector<vector<int>> child(m+1);
        for(int i=1; i<=m; ++i){
            int a;
            cin >> cost[i] >> a >> f[i];
            val[i] = cost[i] * a;
            if(f[i]) child[f[i]].push_back(i);
        }

        vector<int> dp(n+1, 0);
        for(int i=1; i<=m; ++i){
            if(f[i] == 0){
                for(int j = n; j >= cost[i]; --j){
                    dp[j] = max(dp[j], dp[j - cost[i]] + val[i]); // only parent
                    if(child[i].size() > 0){ // choose one child
                        for(int k = 0; k < child[i].size(); ++k){
                            if(j - cost[i] - cost[child[i][k]] >= 0) dp[j] = max(dp[j], dp[j - cost[i] - cost[child[i][k]]] + val[i] + val[child[i][k]]);
                        }
                    }
                    if(child[i].size() > 1){ // choose both child
                        if(j - cost[i] - cost[child[i][0]] - cost[child[i][1]] >= 0) dp[j] = max(dp[j], dp[j - cost[i] - cost[child[i][0]] - cost[child[i][1]]] + val[i] + val[child[i][0]] + val[child[i][1]]);
                    }
                }
            }
        }

        cout << dp[n] << '\n';
    }
    return 0;
}