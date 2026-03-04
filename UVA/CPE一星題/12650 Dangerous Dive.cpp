#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r;
    while(cin >> n >> r){
        int arr[n+1];
        for(int i=1; i<=n; ++i) arr[i] = 1;
        int now;
        for(int i=1; i<=r; ++i){
            cin >> now;
            arr[now] = -1;
        }
        if(n == r){
            cout << "*\n";
            continue;
        }
        for(int i=1; i<=n; ++i){
            if(arr[i] == 1) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}