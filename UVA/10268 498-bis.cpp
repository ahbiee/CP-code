#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define ll long long

using namespace std;

int main(){
    string line;
    while(getline(cin, line)){
        stringstream ss1(line);
        int x;
        ss1 >> x;

        getline(cin, line);
        stringstream ss2(line);
        vector<ll> c; // coefficient 係數
        ll a;
        while(ss2 >> a) c.push_back(a);

        int n = c.size() - 1;
        ll result = 0;
        // 用秦九韶算法
        for(int i=0; i < n; ++i){
            result = result * x + c[i] * (n-i);
        }
        cout << result << '\n';
    }
    return 0;
}