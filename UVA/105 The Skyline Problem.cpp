#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, h, r;
    int arr[10005] = {0};
    while(cin >> l >> h >> r){
        for(int i=l; i<r; ++i){
            if(arr[i] < h) arr[i] = h;
        }
    }

    bool first = true;
    for(int i=0; i<10004; ++i){
        if(arr[i] != arr[i+1]){
            if(first) first = false;
            else cout << ' ';

            cout << i+1 << ' ' << arr[i+1];
        }
    }
    cout << '\n';

    return 0;
}