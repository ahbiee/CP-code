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
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size()-1;
        while(l < r){
            if(!isalnum(s[l])) ++l;
            else if(!isalnum(s[r])) --r;
            else{
                if(tolower(s[l]) == tolower(s[r])){
                    ++l;
                    --r;
                }
                else return false;
            }
        }
        return true;
    }
};