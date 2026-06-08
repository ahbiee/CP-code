#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v, pos;

bool solve(){
    // b - a = c - b -> c = 2b-a
    for(int a = 0; a < n; ++a){ // 枚舉位置
        for(int b = a+1; b < n; ++b){ // 枚舉位置
            int val = 2 * v[b] - v[a];
            if(val >= n || val < 0) continue;
            if(pos[val] > b) return true;
        }
    }
    return false;
}

int main() {
    char colon;
    while(cin >> n && n){
        cin >> colon;
        pos.resize(n);
        v.resize(n);
        int num;
        for(int i=0; i<n; ++i){
            cin >> num;
            v[i] = num;
            pos[num] = i;
        }
        if(solve()) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}
/*
3: 0 2 1
5: 2 0 1 3 4
6: 2 4 3 5 0 1
0
*/