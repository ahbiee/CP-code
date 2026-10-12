#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 505;
char arr[MAXN][MAXN], ans[MAXN][MAXN];

void test(int i, int j){
    for(int k=0; k<4; ++k){ // A, B, C, D
        if(arr[i][j] == 'A'+k) continue;
        if(i > 0 && ans[i-1][j] == 'A'+k) continue;
        if(j > 0 && ans[i][j-1] == 'A'+k) continue;

        ans[i][j] = 'A'+k;
        return;
    }
}

int main() {
    int n, m;
    cin >> n >> m >> ws;
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> arr[i][j];
            test(i, j);
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}