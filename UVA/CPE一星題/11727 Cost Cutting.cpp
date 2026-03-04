#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int arr[3];
    for(int kase = 1; kase <=t; ++kase){
        for(int i=0; i<3; ++i){
            cin >> arr[i];
        }
        sort(arr, arr+3);
        cout << "Case " << kase << ": " <<  arr[1] << '\n';
    }
}