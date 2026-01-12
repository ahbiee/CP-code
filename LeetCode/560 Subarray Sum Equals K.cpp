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
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp; // <prefixSum, appeared how many times>

        // init, prefixSum 0 has appeared before any numbers be inserted
        mp.clear();
        mp[0] = 1;

        int sum = 0; // prefixSum
        int ans = 0; // total number
        /*
        assume:
        sum = x;
        sum + something = k;
        -> sum-k = something;
        we find if there is "something" whose index is before "sum"
        -> we find mp[sum-k] to find "something"'s appearance
        */
        for(int i=0; i<nums.size(); ++i){
            sum += nums[i]; // count the prefix sum until index i
            ans += mp[sum-k]; // if there is "something" which allows sum+something = k
            // -> that means something appears, and we find the appearance
            mp[sum]++; // remember to add 1 to mp[sum]
        }
        return ans;
    }
};