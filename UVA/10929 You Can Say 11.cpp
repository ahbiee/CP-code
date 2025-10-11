#include <iostream>
#include <cmath>

using namespace std;

int main(){
    string str;

    while(cin >> str){
        if(str == "0") break;
        int odd = 0, even = 0;
        for(int i=0; i<str.size(); ++i){
            if(i%2 == 1) odd += str[i]-48;
            else even += str[i]-48;
        }
        int diff = abs(odd - even);
        if(diff % 11 == 0) cout << str << " is a multiple of 11.\n";
        else cout << str << " is not a multiple of 11.\n";
    }
    return 0;
}