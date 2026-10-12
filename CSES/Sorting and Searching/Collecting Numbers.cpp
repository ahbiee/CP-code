#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int pos[n+1];
    for(int i=1; i<=n; ++i){
        int cur;
        cin >> cur;
        pos[cur] = i;
    }
    int cnt = 1;
    for(int i=1; i<n; ++i){
        if(pos[i+1] < pos[i]) ++cnt;
    }
    cout << cnt << '\n';
    return 0;
}