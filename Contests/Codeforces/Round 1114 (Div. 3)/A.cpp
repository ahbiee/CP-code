#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int v[3];
        cin >> v[0] >> v[1] >> v[2];
        sort(v, v+3);
        cout << min(abs(v[0]-v[1]), abs(v[1]-v[2])) << '\n';
    }
    return 0;
}