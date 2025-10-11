#include <iostream>

using namespace std;

int main(){
    int n, sum;
    while(cin >> n){
        if(n == 0) break;
        sum = n;
        while(sum >= 10){
            n = sum;
            int tmp = 0;
            while(n > 0){
                tmp += n%10;
                n /= 10;
            }
            sum = tmp;
        }
        cout << sum << '\n';
    }
    return 0;
}