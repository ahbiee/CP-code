#include <bits/stdc++.h>
using namespace std;
bool isUgly(int num){
    if(num == 1) return true;
    if(num % 2 == 0) return isUgly(num/2);
    if(num % 3 == 0) return isUgly(num/3);
    if(num % 5 == 0) return isUgly(num/5);
    return false;
}
int main(){
    int counts = 1;
    int n = 2;
    while(counts != 1500){
        if(isUgly(n)) ++counts;
        ++n;
    }
    cout << "The 1500'th ugly number is " << n << ".\n";
    return 0;
}