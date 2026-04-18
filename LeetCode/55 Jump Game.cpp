#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        int idx = 0;
        int max_jump = nums[idx];
        while(max_jump > 0 && idx < nums.size()-1){
            max_jump = max(--max_jump, nums[++idx]);
        }
        if(idx == nums.size()-1) return true;
        else return false;
    }
};