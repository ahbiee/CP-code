#include <bits/stdc++.h>
using namespace std;

struct pos{
    int l, r;
    bool operator<(const pos&o) const{
        return l < o.l;
    }
};

int main() {
    int len, gas;
    int x, r;

    while(cin >> len >> gas && len && gas){
        vector<pos> v;
        for(int i=0; i<gas; ++i){
            cin >> x >> r;
            v.push_back({x-r, x+r});
        }
        sort(v.begin(), v.end());

        int i=0;
        int farthest = 0;
        int cnt = 0;
        bool noAns = false;
        while(farthest < len){
            int cur = farthest;
            while(i < gas && v[i].l <= farthest){
                cur = max(cur, v[i].r);
                ++i;
            }
            if(cur == farthest){
                noAns = true;
                break;
            }
            farthest = cur;
            ++cnt;
        }
        if(noAns) cout << -1 << '\n';
        else cout << gas-cnt << '\n';
    }
    return 0;
}
/*
40 3
5 5
20 10
40 10
40 5
5 5
11 8
20 10
30 3
40 10
40 5
0 10
10 10
20 10
30 10
40 10
40 3
10 10
18 10
25 10
40 3
10 10
18 10
25 15
0 0
*/