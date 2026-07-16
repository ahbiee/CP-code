#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge{
    int u, v;
    ll w;
    bool operator<(const Edge &o) const{
        return w < o.w;
    }
};

vector<int> f;

int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

bool unite(int a, int b){
    int fa = f[a], fb = f[b];
    if(fa == fb) return false;
    f[fb] = fa;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    f.resize(n);
    for(int i=0; i<n; ++i) f[i] = i;
    for(int i=0; i<m; ++i){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end());

    int cnt = 0;
    vector<Edge> selected;

    for(Edge &e : edges){
        if(unite(e.u, e.v)){
            selected.push_back(e);
            ++cnt;
            if(cnt == n-1) break;
        }
    }

    sort(selected.begin(), selected.end());
    ll total = 0;
    for(int i=n-2; i>=0; --i){
        total += selected[i].w * (n-1-i);
    }

    cout << total << '\n';
    return 0;
}