#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // 整體陣列的mod值
        int mod = 0;
        for(int num : nums) mod = (mod + num) % p;

        if(mod == 0) return 0;
        
        map<int, int> mp; // mod value, lastIndex
        mp.insert({0, -1});

        int ans = 0x3f3f3f3f;
        for(int i=0, curr=0, find; i<nums.size(); ++i){
            curr = (curr + nums[i]) % p; // 累計到目前為止的mod值
            find = (curr - mod + p) % p; // 我往左要移除mod多少的值後才能達成目標
            if(mp.count(find)) ans = min(ans, i - mp[find]);
            mp[curr] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};