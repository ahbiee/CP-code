#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main(){
    int k;
    while(cin >> k){
        v.clear();
        for(int y = k+1; y<=2*k; ++y){
            if((k*y) % (y-k) == 0){
                int x = (k*y)/(y-k);
                v.push_back({x, y});
            }
        }

        cout << v.size() << '\n';

        for(auto &p : v){
            printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
        }
    }
    return 0;
}