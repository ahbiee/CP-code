#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}   

int main(){
    int n;
    cin >> n;
    for(int cases = 1; cases <= n; ++cases){
        string s1, s2;
        cin >> s1 >> s2;

        int a=0, b=0;

        for(char c : s1) a = a*2 + (c-'0');
        for(char c : s2) b = b*2 + (c-'0');

        cout << "Pair #" << cases << ": ";
        int g = gcd(a, b);  
        if(g > 1){
            cout << "All you need is love!\n";
        }
        else cout << "Love is not all you need!\n";
    }
    return 0;
}