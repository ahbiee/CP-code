#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int f[maxn];
vector<int> v;

int find(int x){return x == f[x] ? x : f[x] = find(f[x]);}

void unite(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return;
    f[pb] = pa;
}

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n, x, y;
        cin >> n >> x >> y;
        v.resize(n+1);
        for(int i=1; i<=n; ++i) {cin >> v[i]; f[i] = i;}
        for(int i=1; i+x<=n; ++i) unite(i, i+x);
        for(int i=1; i+y<=n; ++i) unite(i, i+y);

        bool ok = true;
        for(int i=1; i<=n; ++i){
            if(find(i) != find(v[i])){
                ok = false;
                break;
            }
        }

        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}