#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    if(x == 1) return false;
    if(x <= 3) return true;
    if(x % 2 == 0 || x % 3 == 0) return false;
    for(int i=5; i*i<=x; i+=6){
        if(x % i == 0 || x % (i+2) == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        bool p1 = isPrime(a);
        bool p2 = isPrime(b);
        if(p1 && p2 && b-a == 2) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}