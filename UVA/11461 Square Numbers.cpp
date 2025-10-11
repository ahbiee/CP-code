#include <iostream>
#include <cmath>

using namespace std;

bool is_square(int n){
    if(n == 1) return true;
    int num = (int)sqrt(n);
    if(num * num == n) return true;
    return false;
}

int main(){
    int a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0) break;
        int count = 0;
        for(int i=a; i<=b; ++i){
            if(is_square(i)) count++;
        }
        cout << count << '\n';
    }
    return 0;
}