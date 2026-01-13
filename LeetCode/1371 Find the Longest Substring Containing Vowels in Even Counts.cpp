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
    int findTheLongestSubstring(string s) {
        int mp[32]; // uoiea = 00000 -> 11111 => 0~31
        for(int i=0; i<32; ++i){
            mp[i] = -2; // don't exists
        }
        mp[0] = -1; // initially 00000

        int ans = 0;
        int sum = 0;
        for(int i=0, m; i<s.length(); ++i){
            m = move(s[i]);
            if(m != -1) sum ^= 1 << m;
            if(mp[sum] != -2) ans = max(ans, i - mp[sum]);
            else mp[sum] = i;
        }
        return ans;
    }

    int move(char c){
        switch(c){
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default: return -1;
        }
    }
};