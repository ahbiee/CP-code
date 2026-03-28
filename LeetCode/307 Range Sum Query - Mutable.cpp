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

#define lowbit(x) (x&-x)

vector<int> v, BIT;

class NumArray {
public:
    void build(){
        int cur;
        for(int i=1; i<v.size(); ++i){
            cur = i;
            while(cur < v.size()){
                BIT[cur] += v[i];
                cur += lowbit(cur);
            }
        }
    }

    int sum(int x){
        int total = 0;
        while(x > 0){
            total += BIT[x];
            x -= lowbit(x);
        }
        return total;
    }

    NumArray(vector<int>& nums) {
        v.assign(nums.size()+1, 0);
        BIT.assign(nums.size()+1, 0);
        for(int i=1; i<=nums.size(); ++i) v[i] = nums[i-1];
        build();
    }
    
    void update(int index, int val) {
        ++index;
        int diff = val - v[index];
        v[index] = val;
        while(index < v.size()){
            BIT[index] += diff;
            index += lowbit(index);
        }
    }
    
    int sumRange(int left, int right) {
        return sum(right+1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */