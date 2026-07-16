#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int a, b;
        cin >> a >> b;
        if(a % b == 0 && b % a == 0){
            cout << "Draw\n";
        }
        else if(a % b == 0){
            cout << "1\n";
        }
        else if(b % a == 0){
            cout << "2\n";
        }
        else{
            cout << "Draw\n";
        }
    }
    return 0;
}