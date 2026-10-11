#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int mp[26] = {};
    for(char c : s) mp[c-'A']++;

    int odd_cnt = 0;
    for(int i=0; i<26; ++i){
        if(mp[i] % 2 != 0) ++odd_cnt;
    }
    if(odd_cnt > 1){
        cout << "NO SOLUTION\n";
        return 0;
    }
    string ans = "";
    char odd;
    for(int i=0; i<26; ++i){
        char cur = 'A' + i;
        if(mp[i] % 2 == 1){
            odd = cur;
            mp[i]--; // 預先拿出來，給後面用
        }
        string app(mp[i]/2, cur);
        ans += app;
    }
    string l = ans;
    if(odd_cnt) ans += odd;
    reverse(l.begin(), l.end());
    ans += l;
    cout << ans << '\n';
    return 0;
}