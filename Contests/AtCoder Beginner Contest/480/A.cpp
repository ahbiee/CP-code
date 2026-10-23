#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, d;

    char x;
    for(int i=0; i<4; ++i){
        cin >> x;
        if(x == 'A') a = i;
        if(x == 'D') d = i;
    }
    if((a == 0 && d == 3) || (a == 3 && d == 0) || (a == 1 && d == 2) || (a == 2 && d == 1)) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}