#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printBangla(unsigned long long int n){
    if(n >= 10000000){
        printBangla(n/10000000);
        cout << " kuti";
        n %= 10000000;
    }
    if(n >= 100000){
        printBangla(n/100000);
        cout << " lakh";
        n %= 100000;
    }
    if(n >= 1000){
        printBangla(n/1000);
        cout << " hajar";
        n %= 1000;
    }
    if(n >= 100){
        printBangla(n/100);
        cout << " shata";
        n %= 100;
    }
    if(n > 0){
        cout << ' ' << n;
    }
}

int main(){
    vector<string> ans;
    unsigned long long int num;
    int cases = 1;
    while(cin >> num){
        ans.clear();
        printf("%4d.", cases);
        if(num == 0) cout << " 0";
        else printBangla(num);
        cout << '\n';
        ++cases;
    }
    return 0;
}