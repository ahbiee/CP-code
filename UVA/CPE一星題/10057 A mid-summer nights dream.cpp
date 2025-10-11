#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin >> n){
        vector<int> v(n);
        for(int i=0; i<n; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        int a = v[(n-1)/2];
        int b = v[n/2];
        int first = a;
        int second = 0;
        for(int x : v){
            if(x >= a && x <= b) ++second;
        }
        int third = b-a+1;

        cout << first << ' ' << second << ' ' << third << '\n';
    }
    return 0;
}