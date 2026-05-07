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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        int cur = -1;
        while(l < r){
            cur = numbers[l] + numbers[r];
            if(cur < target) ++l;
            else if(cur > target) --r;
            else return {l+1, r+1};
        }
        return {};
    }
};
