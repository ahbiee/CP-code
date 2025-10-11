#include <iostream>

using namespace std;

int main(){
    unsigned long long s, d;
    while(cin >> s >> d){
        while(d > s){
            d-=s;
            ++s;
        }
        cout << s << '\n';
    }
    return 0;
}