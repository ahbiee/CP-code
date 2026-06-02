#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, d;
    while(cin >> x >> d){
        if(x*2 > d) cout << "take it\n";
        else cout << "double it\n";
    }
    return 0;
}