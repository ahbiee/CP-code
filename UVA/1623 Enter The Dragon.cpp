#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

#define MAXN 1000005

using namespace std;
using ll = long long;

vector<int> forecast(MAXN), nearest_empty(MAXN), nearest_rain(MAXN), ans(MAXN);
int n, m; // n number of lakes, m days of forecast

int find(int x){
    if(x == nearest_empty[x]) return x;
    return nearest_empty[x] = find(nearest_empty[x]);
}

bool solve(){
    for(int i=1; i<=n; ++i) nearest_rain[i] = 0;
    for(int i=1; i<=m; ++i){
        if(forecast[i] == 0) continue;
        int empty = find(nearest_rain[forecast[i]]);
        if(empty <= i){
            ans[empty] = forecast[i];
            nearest_empty[empty] = find(empty+1);
        }
        else return false;
        nearest_rain[forecast[i]] = i;
    }
    printf("YES\n");
    for(int i=1; i<=m; ++i) if(forecast[i] == 0) printf("%d ", ans[i]);
    printf("\n");
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int kase;
    cin >> kase;

    while(kase--){
        cin >> n >> m;
        for(int i=1; i<=m; ++i){
            cin >> forecast[i];
            ans[i] = 0;
        }
        int empty = m+1;
        nearest_empty[m+1] = m+1;
        for(int i=m; i>=0; --i){
            if(forecast[i] == 0 && i != 0) empty = i;
            nearest_empty[i] = empty;
        }
        if(!solve()) printf("NO\n");
    }
    return 0;
}

/*
4
2 4
0 0 1 1
2 4
0 1 0 2
2 3
0 1 2
2 4
0 0 0 1

NO
YES
1 2
NO
YES
0 1 0
*/