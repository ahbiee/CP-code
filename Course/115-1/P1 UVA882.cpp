// 3D dp
#include <bits/stdc++.h>
using namespace std;

static const int MAXK = 15, MAXN = 105, INF = 0x3f3f3f3f;

int dp[MAXK][MAXN][MAXN];
bool visited[MAXK][MAXN][MAXN];

int dfs(int k, int i, int j){
    if(i > j) return 0;
    if(k == 0) return INF;
    if(visited[k][i][j]) return dp[k][i][j];
    visited[k][i][j] = true;
    int &ret = dp[k][i][j];

    ret = INF;
    for(int x = i; x <= j; ++x){
        ret = min(ret, x + max(dfs(k-1, i, x-1), dfs(k, x+1, j)));
    }
    return ret;
}

int main() {
    freopen("882_in.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    int kase, k, n;
    cin >> kase;
    memset(visited, false, sizeof(visited));
    while(kase--){
        cin >> k >> n;
        cout << dfs(k, 1, n) << '\n';
    }
    return 0;
}