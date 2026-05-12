#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int kase;
    cin >> kase;
    int n, m;
    string text;
    vector<vector<int>> g;
    vector<vector<bool>> wall;
    while(kase--){
        cin >> n >> m >> ws;
        g.assign(n+1, vector<int>(m+1, 0));
        wall.assign(n+1, vector<bool>(m+1, false));

        int row, col;
        for(int i=0; i<n; ++i){
            getline(cin, text);
            stringstream ss(text);
            ss >> row;
            while(ss >> col) wall[row][col] = true;
        }

        g[1][1] = 1; // 特判

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if((i==1 && j==1) || wall[i][j]) continue;
                if(i > 1) g[i][j] += g[i-1][j];
                if(j > 1) g[i][j] += g[i][j-1];
            }
        }

        cout << g[n][m] << '\n';
        if(kase) cout << '\n';
    }
    return 0;
}