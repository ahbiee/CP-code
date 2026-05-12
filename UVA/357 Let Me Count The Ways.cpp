#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[30005][6] = {};
int coin[6] = {0, 1, 5, 10, 25, 50};

int main() {
    for(int j=1; j<=5; ++j) dp[0][j] = 1;
    
    for(int i=1; i<=30000; ++i){
        for(int j=1; j<=5; ++j){
            if(j == 1) dp[i][j] = 1;
            else{
                dp[i][j] = dp[i][j-1];
                if(i >= coin[j]){
                    dp[i][j] += dp[i-coin[j]][j];
                }
            }
        }
    }

    int n;
    while(~scanf("%d", &n)){
        if(n <= 4) printf("There is only 1 way to produce %d cents change.\n", n);
        else printf("There are %lld ways to produce %d cents change.\n", dp[n][5], n);
    }

    return 0;
}