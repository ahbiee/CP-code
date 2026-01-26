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
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1); // record the last seen position for each character
        // 原本用map寫但卡測資，因為map預設所有東西都是0，而我們要設定的值是-1
        // 如果要用map寫，在修改l的時候需要先判斷資料是否存在(last.find(curr))
        char curr;
        int ans = 0;
        for(int l=0, r=0; r<s.length(); ++r){
            curr = s[r];
            l = max(l, last[curr]+1);
            ans = max(ans, r-l+1);
            last[curr] = r;
        }
        return ans;
    }
};