#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    vector<vector<string>> dp(n, vector<string>(m)); // 用vector開動態陣列，避免開 500*500 的 string 導致TLE

    // 讀入與初始化
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> arr[i][j];
            dp[i][j] = "0";
        }
    }

    if(arr[0][0] == 'A') dp[0][0] = "1";

    // 處理第一 column
    for(int i=1; i<n; ++i){
        dp[i][0] = dp[i-1][0];
        if(arr[i][0] == 'A'){
            dp[i][0][dp[i][0].length()-1] = '1';
        }
        else if(arr[i][0] == 'B'){
            if(dp[i][0] != "0") dp[i][0] += "0";
        }
    }

    // 處理第一 row
    for(int i=1; i<m; ++i){
        dp[0][i] = dp[0][i-1];
        if(arr[0][i] == 'A'){
            dp[0][i][dp[0][i].length()-1] = '1';
        }
        else if(arr[0][i] == 'B'){
            if(dp[0][i] != "0") dp[0][i] += "0";
        }
    }

    // 跑 DP 表格
    string up, left;
    for(int i=1; i<n; ++i){
        for(int j=1; j<m; ++j){
            up = dp[i-1][j];
            left = dp[i][j-1];
            if(arr[i][j] == 'A'){
                up[up.length()-1] = '1';
                left[left.length()-1] = '1';
            }
            else if(arr[i][j] == 'B'){
                if(up != "0") up += "0";
                if(left != "0") left += "0";
            }

            if(up.length() > left.length()) dp[i][j] = up;
            else if(left.length() > up.length()) dp[i][j] = left;
            else dp[i][j] = max(up, left);
        }
    }
    cout << dp[n-1][m-1] << '\n';
    return 0;
}