class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // return dfs(nums, target, 0, 0);
        // return dfs2(nums, target, 0, 0);  better with mp.clear()
        return knapsack(nums, target);
    }

    int dfs1(const vector<int> &nums, int target, int i, int sum){
        if(i == nums.size()){
            return sum == target ? 1 : 0;
        }
        return dfs1(nums, target, i+1, sum + nums[i]) + dfs1(nums, target, i+1, sum - nums[i]);
    }

    map<pair<int, int>, int> mp; // at <i, sum>, return 1 or 0 if exist
    int dfs2(const vector<int> &nums, int target, int i, int sum){
        if(i == nums.size()){
            return sum == target ? 1 : 0;
        }
        auto it = mp.find({i, sum});
        if(it != mp.end()) return it->second;
        
        int ans = dfs2(nums, target, i+1, sum+nums[i]) + dfs2(nums, target, i+1, sum-nums[i]);

        return mp[{i, sum}] = ans;
    }

    int knapsack(const vector<int> &nums, int target){
        int total = 0;
        for(int num : nums) total += num;
        if(total < target || (total & 1) ^ (target & 1) == 1) return 0;

        int t = (total + target) / 2;
        if(t < 0) return 0; // target may be negative, cause to negative index

        int dp[t+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; // to achieve sum 0 : empty set
        
        for(int num : nums){
            for(int j = t; j >= num; --j){
                dp[j] = dp[j] + dp[j - num]; // asking for ways, so just addition
            }
        }
        return dp[t];
    }
};