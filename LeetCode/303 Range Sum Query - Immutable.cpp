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

// https://leetcode.com/problems/range-sum-query-immutable/description/
#define MAXN 10005

class NumArray {
public:
    int prefix[MAXN] = {};

    NumArray(vector<int>& nums) {
        prefix[0] = 0;
        for(int i = 1; i<=nums.size(); ++i){
            prefix[i] = nums[i-1] + prefix[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */