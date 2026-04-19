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
    int dp[50];
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n);
    }

    int solve(int cur, int n){
        if(cur == n) return 1;
        if(cur > n) return 0;
        if(dp[cur] != -1) return dp[cur];
        dp[cur] = solve(cur+1, n) + solve(cur+2, n);
        return dp[cur];
    }
};