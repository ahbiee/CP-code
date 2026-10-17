// 此版本無狀態壓縮

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> prefix(piles.size()+1, vector<int>(1, 0));
        // 轉成分組背包(存前綴和)，表示各種方案 -> 不選，選1，選2，...，全選
        for(int i=0; i<piles.size(); ++i){
            for(int j = 0; j < min((int)piles[i].size(), k); ++j){
                prefix[i+1].push_back(piles[i][j] + prefix[i+1][j]);
            }
        }

        vector<vector<int>> dp(piles.size()+1, vector<int>(k+1));

        for(int i=1; i<=piles.size(); ++i){
            for(int j = 0; j <= k; ++j){
                dp[i][j] = dp[i-1][j];
                for(int m = 1; m <= min((int)prefix[i].size()-1, j); ++m){
                    dp[i][j] = max(dp[i][j], dp[i-1][j - m] + prefix[i][m]);
                }
            }
        }
        
        return dp[piles.size()][k];
    }
};