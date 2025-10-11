#include <iostream>
#include <cmath>

using namespace std;

int gcd(int x, int y){
    if(x % y == 0) return y;
    else return gcd(y, x%y);
}

int main(){
    int n, g;
    while(cin >> n){
        if(n == 0) break;
        g = 0;
        for(int i=1; i<n; ++i){
            for(int j=i+1; j<=n; ++j){
                g += gcd(i, j);
            }
        }
        cout << g << '\n';
    }
    return 0;
}