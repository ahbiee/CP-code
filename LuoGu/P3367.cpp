#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n, m;
vector<int> f(MAXN);

int find(int x){
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}

bool isSameSet(int x, int y){
    return (find(f[x]) == find(f[y]));
}

void Union(int x, int y){
    f[find(x)] = find(y);
}

int main(){
    cin >> n >> m;
    int op, x, y;

    for(int i=1; i<=n; ++i){
        f[i] = i;
    }

    while(m--){
        cin >> op >> x >> y;
        if(op == 1){
            Union(x, y);
        }
        else{
            if(isSameSet(x, y)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}