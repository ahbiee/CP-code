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
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int prefix[105];
        prefix[0] = 0;
        for(int i = 0; i<nums.size(); ++i){
            prefix[i+1] = nums[i] + prefix[i];
        }

        int ans = 0x3f3f3f3f;
        bool found = false;
        int tmp;
        for(int i=0; i<nums.size(); ++i){
            for(int j=l; j<=r; ++j){
                if(i + j > nums.size()) break;
                tmp = prefix[i + j] - prefix[i];
                if(tmp > 0){
                    ans = min(ans, tmp);
                    found = true;
                }
            }
        }

        return found ? ans : -1;
    }
};