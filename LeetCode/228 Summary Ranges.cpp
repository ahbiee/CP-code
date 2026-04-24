#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty()) return ans;
        int l, r, idx=0;
        while(idx < nums.size()){
            r = l = nums[idx];
            while(idx < nums.size()-1 && nums[idx+1] == nums[idx]+1){
                ++r;
                ++idx;
            }
            if(l == r) ans.push_back(to_string(l));
            else ans.push_back(to_string(l) + "->" + to_string(r));
            ++idx;
        }
        return ans;
    }
};