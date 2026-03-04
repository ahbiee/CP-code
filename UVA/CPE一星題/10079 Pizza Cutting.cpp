#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll table[210000005] = {};

int main(){
    table[0] = 1;
    for(int i=1; i<210000001; ++i){
        table[i] = table[i-1] + i;
    }
    int num;
    while(cin >> num){
        if(num < 0) break;
        cout << table[num] << '\n';
    }
    
    return 0;
}