#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int v[3];
        cin >> v[0] >> v[1] >> v[2];
        sort(v, v+3);
        int cnt = 0;
        while(v[0] != v[1] && v[0] != v[2] && v[1] != v[2]){
            ++cnt;
            --v[2];
            ++v[0];
            sort(v, v+3);
        }
        cout << cnt << '\n';
    }
    return 0;
}