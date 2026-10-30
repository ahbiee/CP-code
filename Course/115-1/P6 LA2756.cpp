// Math
#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        cout << (n/2) * ((n-1)/2) << '\n'; // 推得公式
    }
    return 0;
}