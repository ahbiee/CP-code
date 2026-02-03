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
    string minWindow(string s, string t) {
        int tSize = t.length();
        int sSize = s.length();
        if(tSize > sSize) return "";
        int min_len=0x3f3f3f3f, start_pos=-1; // 紀錄答案
        map<char, int> mp; // 紀錄字母出現次數
        int debt=tSize; // 總欠債字母數 (debt == 0 代表開始有答案)
        for(int i=0; i<tSize; ++i) mp[t[i]]--; // 欠債

        for(int l=0, r=0; r<sSize; ++r){
            if(++mp[s[r]] <= 0) debt--; // 還給一個，然後檢查
            // 如果原本有欠就會還，所以總欠債就可以減少

            if(debt == 0){ // 代表已經還清，要檢查左邊界
                while(mp[s[l]] > 0){ // 持續將左邊界往右推
                    mp[s[l++]]--;
                }
                // 檢查是否為更短的長度
                if(min_len > r-l+1){
                    min_len = r-l+1;
                    start_pos = l;
                }
            }
        }

        return min_len == 0x3f3f3f3f ? "" : s.substr(start_pos, min_len);
    }
};