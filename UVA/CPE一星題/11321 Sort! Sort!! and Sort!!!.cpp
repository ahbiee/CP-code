#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

bool cmp(int x, int y){
    if((x%m) != (y%m)) return (x%m) < (y%m);
    if(x%2 == 1 && y%2 == 1) return x > y;
    if(x%2 == 0 && y%2 == 0) return x < y;
    else return x%2;
}

int main(){
    while(cin >> n >> m){
        cout << n << ' ' << m << '\n';
        if(n == 0 && m == 0) break;
        int arr[n] = {};
        for(int i=0; i<n; ++i) cin >> arr[i];
        sort(arr, arr+n, cmp);
        for(int i=0; i<n; ++i) cout << arr[i] << '\n';
    }
    return 0;
}