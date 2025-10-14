#include <iostream>

using namespace std;

int father[1005];

int find(int a){
    if(father[a] == a) return a;
    father[a] = find(father[a]);
    return father[a];
}

void merge(int a, int b){
    int fa = find(a);
    int fb = find(b);
    if(fa != fb) father[fb] = fa;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m; // n people, m combines
        for(int i=1; i<=n; ++i){
            father[i] = i;
        }
        int a, b;
        while(m--){
            cin >> a >> b >> ws;
            merge(a, b);
        }

        int table = 0;
        for(int i=1; i<=n; ++i){
            if(father[i] == i) ++table;
        }
        cout << table << '\n';
    }

    return 0;
}