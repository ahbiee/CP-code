#include <bits/stdc++.h>
using namespace std;

struct station{
    int l, r;
    bool operator<(const station&o) const{
        return l < o.l;
    };
};

int main() {
    int len, gas;
    int pos, rad;
    vector<station> v;
    while(scanf("%d%d", &len, &gas)==2 && len){
        v.clear();
        int a, b;
        for(int i=0; i<gas; ++i){
            scanf("%d%d", &pos, &rad);
            a = pos-rad;
            b = pos+rad;
            a = max(a, 0);
            b = min(b, len);
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());

        int max_r;
        int prev = 0;
        int ans = 0;
        int idx = 0;
        while(prev < len){
            max_r = prev;
            while(idx < gas && v[idx].l <= prev){
                max_r = max(max_r, v[idx].r);
                ++idx;
            }
            if(max_r == prev){
                ans = -1;
                break;
            }
            prev = max_r;
            ++ans;
        }

        if(ans == -1) printf("-1\n");
        else printf("%d\n", gas-ans);
    }

    return 0;
}
