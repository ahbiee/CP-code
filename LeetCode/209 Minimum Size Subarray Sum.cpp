#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INF;
        for(int l=0, r=0, sum=0; r < nums.size(); ++r){
            sum += nums[r];
            while(sum - nums[l] >= target){
                sum -= nums[l++];
            }
            if(sum >= target) ans = min(ans, r-l+1);
        }
        return ans == INF ? 0 : ans;
    }
};