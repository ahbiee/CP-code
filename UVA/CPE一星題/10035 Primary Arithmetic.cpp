#include <iostream>

using namespace std;

int main(){
    long long int a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0) break;
        int carry = 0;
        int count = 0;
        while(a > 0 || b > 0){
            int num = a%10 + b%10 + carry;
            if(num >= 10){
                carry = num / 10;
                count++;
            }
            a/=10;
            b/=10;
        }
        if(count > 1) cout << count << " carry operations.\n";
        else if(count == 1) cout << "1 carry operation.\n";
        else cout << "No carry operation.\n";
    }
    return 0;
}