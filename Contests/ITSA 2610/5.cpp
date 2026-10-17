#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int lines, target;
    cin >> lines >> target;
    vector<vector<int>> v(1); // v[0] is unused, v stores prefix sum

    int n;
    for(int line = 1; line <= lines; ++line){
        cin >> n;
        v.push_back(vector<int>(n+1, 0)); // v[line][0] is unused
    }

    int tmp;
    for(int i=1; i<=lines; ++i){
        for(int j=1; j<v[i].size(); ++j){ // range [1, max_size]
            cin >> tmp;
            v[i][j] = v[i][j-1] + tmp;
        }
    }

    vector<vector<int>> dp(lines+1, vector<int>(target+1, -1)), choose(lines+1, vector<int>(target+1, 0));
    dp[0][0] = 0;
    for(int i=1; i<=lines; ++i){
        for(int j=0; j<=target; ++j){
            // didn't choose
            dp[i][j] = dp[i-1][j];
            choose[i][j] = 0;

            // enumerate every possibilities
            for(int k=1; k <= min(j, (int)v[i].size()-1); ++k){
                if(dp[i-1][j-k] != -1 && dp[i-1][j-k] + v[i][k] > dp[i][j]){
                    choose[i][j] = k;
                    dp[i][j] = dp[i-1][j-k] + v[i][k];
                }
            }
        }
    }

    cout << dp[lines][target] << '\n';

    vector<int> ans(lines+1, 0);
    int remain = target;
    for(int i=lines; i>=1; --i){ // backtarcking
        ans[i] = choose[i][remain];
        remain -= ans[i];
    }
    
    bool first = true;
    for(int i=1; i<= lines; ++i){
        if(ans[i]){
            if(!first) cout << ' ';
            first = false;
            cout << '(' << i << ',' << ans[i] << ')';
        }
    }
    cout << '\n';
    return 0;
}

/*
4 5
4 2 2 2
8 6 45 5
12 10
6 20
22 3
*/