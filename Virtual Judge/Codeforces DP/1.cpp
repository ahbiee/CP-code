#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<vector<char>> v(2, vector<char>(n));
        for(int i=0; i<2; ++i)
            for(int j=0; j<n; ++j)
                cin >> v[i][j];
        vector<vector<bool>> dp(2, vector<bool>(n, false)); // dp[i][j] means if we can reach
        dp[0][0] = true;
        for(int col = 0; col < n; ++col){
            for(int row = 0; row < 2; ++row){
                // we don't need to go left and top, because only > keeps us go forward
                
                // if can't reach, skip it
                if(!dp[row][col]) continue;

                // go right
                if(col+2 < n && v[row][col+1] == '>') dp[row][col+2] = true;

                // go down
                if(col + 1 < n && v[1-row][col] == '>') dp[1-row][col+1] = true;
            }
        }

        if(dp[1][n-1]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}