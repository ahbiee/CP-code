#include <bits/stdc++.h>
using namespace std;

static const int MAXT = 1005;
static const int MAXN = 105;

int T[MAXT], val[MAXN];
int dp[MAXT];

int main(){
    int t, m;
    while(cin >> t >> m){
        
        for(int i=1; i<=m; ++i){
            cin >> T[i] >> val[i];
        }

        dp[0] = 0; // 0時間不可能有任何reward
        for(int i=1; i<=m; ++i){
            for(int j=t; j >= T[i]; --j){
                dp[j] = max(dp[j], dp[j - T[i]] + val[i]);
            }
        }

        cout << dp[t] << '\n';
    }
    return 0;
}
/*
70 3
71 100
69 1
1 2

3
*/