#include <bits/stdc++.h>
using namespace std;

int solve(const string& s) {
        int n = s.length();
        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 0; 

        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]}) + 1; 
        }
    }
    return dp[0][n-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int kase;
    cin >> kase;
    while(kase--){
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
    return 0;
}