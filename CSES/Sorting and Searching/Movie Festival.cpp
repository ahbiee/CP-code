#include <bits/stdc++.h>
using namespace std;

struct movie{
    int a, b;
    bool operator<(const movie o) const{
        if(b != o.b) return b < o.b;
        return a < o.a;
    }
};

int main() {
    int n;
    while(cin >> n){
        vector<movie> v(n);
        for(int i=0; i<n; ++i) cin >> v[i].a >> v[i].b;
        sort(v.begin(), v.end());

        int cur_end = v[0].b;
        int chosen = 1; // 最早結束的必可選
        for(auto m : v){
            if(m.a >= cur_end){
                ++chosen;
                cur_end = m.b;
            }
        }
        cout << chosen << '\n';
    }
    return 0;
}