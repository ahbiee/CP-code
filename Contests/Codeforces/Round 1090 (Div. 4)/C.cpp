#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> table;

void build(int _r){
    int l = 1, r = _r;
    while(l <= r){
        table.push_back({l, r-1, r});
        ++l;
        r -= 2;
    }
}

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        table.clear();
        int len;
        cin >> len;
        build(len*3);
        for(int i=0; i<len; ++i){
            if(i) cout << ' ';
            for(int j = 0; j<3; ++j){
                if(j) cout << ' ';
                cout << table[i][j];
            }
        }
        cout << '\n';
    }
    return 0;
}