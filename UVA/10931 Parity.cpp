#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int i;
    while(cin >> i){
        if(i == 0) break;

        bitset<32> b(i);
        string str = b.to_string();
        string ans = str.substr(str.find('1'));
        int parity = b.count();

        cout << "The parity of " << ans << " is " << parity << " (mod 2).\n";
    }
}