#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

#define INF 0x3f3f3f3f
#define MAXN 10005
class Solution_DP {
public:
    int dp[MAXN];
    // 從0到idx的value = dp[idx];

    void solve(vector<int>& nums, int idx){
        if(dp[idx] == INF) return;
        int jumps = nums[idx];
        for(int i=1; i<=jumps; ++i){
            if(idx + i < nums.size()){
                dp[idx+i] = min(dp[idx+i], dp[idx]+1);
            }
        }
    }

    int jump(vector<int>& nums) {;
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        for(int i=0; i<nums.size(); ++i) solve(nums, i);
        return dp[nums.size()-1];
    }
};

class Solution_Greedy {
public:
    int jump(vector<int>& nums){
        if(nums.size() == 1) return 0;
        int jumps = 0;
        int maxi = 0;
        int dist = 0;
        for(int i=0; i<nums.size()-1; ++i){ // cur_idx
            maxi = max(maxi, i + nums[i]);
            if(i == dist){
                dist = maxi;
                ++jumps;

                if(dist >= nums.size()-1) break; // 已經到終點了
            }
        }
        return jumps;
    }
};