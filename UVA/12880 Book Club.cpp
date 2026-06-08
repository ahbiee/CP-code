#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
int n, m;
vector<int> G[MAXN]; // adjacency list
int L[MAXN];
bool S[MAXN], T[MAXN];

bool match(int u){
    S[u] = true;
    for(int i=0; i<G[u].size(); ++i){
        int v = G[u][i];
        if(!T[v]){
            T[v] = true;
            if(L[v] == -1 || match(L[v])){
                L[v] = u;
                return true;
            }
        } 
    }
    return false;
}

int KM(){
    int ret = 0;
    memset(L, -1, sizeof(L));
    for(int i=0; i<n; ++i){
        memset(S, false, sizeof(S));
        memset(T, false, sizeof(T));

        if(match(i)) ++ret;
    }
    return ret;
}

int main() {
    freopen("12880_in.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
    while(cin >> n >> m){
        for(int i=0; i<n; ++i) G[i].clear();
        for(int i=0; i<m; ++i){
            int a, b;
            cin >> a >> b;
            G[a].push_back(b); // directed
        }
        int ans = KM();
        if(ans == n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}