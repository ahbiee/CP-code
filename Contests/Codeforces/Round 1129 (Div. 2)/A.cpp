#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n, k;
        cin >> n >> k;
        int arr[105] = {};
        int tmp;
        for(int i=0; i<n; ++i){
            cin >> tmp;
            arr[tmp]++;
        }

        int total = arr[0];
        int mex = 0;
        while(total >= k && arr[mex] > 0){
            total -= k;
            ++mex;
            total += arr[mex]; 
        }
        cout << mex << '\n';
    }
    return 0;
}