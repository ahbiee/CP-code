#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;
vector<int> G[MAXN]; // adjacency list
int n, color[MAXN]; // 二分圖判定

bool is_bipartite(int u){
    for(int i=0; i<G[u].size(); ++i){
        int v = G[u][i];
        if(color[u] == color[v]) return false;
        if(!color[v]){
            color[v] = 3-color[u];
            if(!is_bipartite(v)) return false;
        }
    }
    return true;
}

int main(){
    while(cin >> n && n){
        for(int i=0; i<n; ++i) G[i].clear();
        int u, v;
        while(cin >> u >> v){
            if(u == 0 && v == 0) break;
            --u;
            --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(color, 0, sizeof(color));
        color[0] = 1;
        if(is_bipartite(0)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}