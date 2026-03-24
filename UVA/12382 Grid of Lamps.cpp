#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, m, n; // t <= 100  // 1 <= m,n <= 1000
    cin >> t;
    while(t--){
        cin >> m >> n;
        vector<int> row(m), col(n);
        int total = 0;
        for(int i=0; i<m; ++i){
            cin >> row[i];
            total += row[i];
        }
        for(int i=0; i<n; ++i) cin >> col[i];

        sort(row.begin(), row.end(), greater<int>()); // big -> small
        sort(col.begin(), col.end(), greater<int>()); // big -> small

        for(int idx = 0; idx < m; ++idx){
            for(int k=0; k < row[idx] && k < n; ++k){
                if(col[k]) --col[k];
                else break;
            }
            sort(col.begin(), col.end(), greater<int>());
        }
        cout << total + accumulate(col.begin(), col.end(), 0) << '\n';
    }
    return 0;
}
/*
3
2 2
2 0
0 2
1 4
2
1 0 1 1
2 4
3 1
0 2 1 2
*/