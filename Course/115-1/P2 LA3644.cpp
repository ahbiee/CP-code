// Disjoint Set
#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 100005;

int f[MAXN];

int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

bool unite(int a, int b){
    int fa = find(a), fb = find(b);
    if(fa == fb) return false;
    f[fb] = fa;
    return true;
}

int main() {
    int a, b;
    while(cin >> a){ // input till EOF
        for(int i=0; i<MAXN; ++i) f[i] = i;
        int cnt = 0;
        while(a != -1){
            cin >> b;
            if(!unite(a, b)) ++cnt; // 計算unite失敗次數
            cin >> a;
        }
        cout << cnt << '\n';
    }
    return 0;
}