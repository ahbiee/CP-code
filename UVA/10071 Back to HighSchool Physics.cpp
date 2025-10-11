#include <iostream>

using namespace std;

int main(){
    int v, t;
    while(cin >> v >> t){
        // v-t圖下面積 (兩倍v*兩倍t/2，簡化後成2*v*t)
        cout << 2*v*t << '\n';
    }
    return 0;
}