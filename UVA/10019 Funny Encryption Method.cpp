#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n >> ws;
    while(n--){
        int num;
        cin >> num;
        bitset<16> b1(num);
        string s = to_string(num);
        int hexValue = stoi(s, nullptr, 16);
        bitset<16> b2(hexValue);
        cout << b1.count() << ' ' << b2.count() << '\n';
    }
    return 0;
}