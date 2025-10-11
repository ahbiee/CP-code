#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int s, d;
        cin >> s >> d;
        if(s < d || (s+d)%2 != 0 || (s-d)%2 != 0){
            cout << "impossible\n";
            continue;
        }
        int a = (s + d) / 2;
        int b = (s - d) / 2;
        if(a < 0 || b < 0){
            cout << "impossible\n";
            continue;
        }
        if(a < b) swap(a, b);
        cout << a << ' ' << b << '\n';
    }
    return 0;
}