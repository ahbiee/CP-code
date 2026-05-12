#include <bits/stdc++.h>
using namespace std;

int n, m; // n vessels, m containers
vector<int> vessel;

bool test(int c){
    int added = 0;
    int used = 1;
    for(int &sz : vessel){
        if(added + sz > c){
            ++used;
            added = sz;
        }
        else{
            added += sz;
        }
        if(used > m) return false;
    }
    return true;
}

int main() {
    while(cin >> n >> m){
        vessel.resize(n);
// the goal is to find capacity c so that m will all c allows all n
        int l = -1, r = 0;
        for(int i=0; i<n; ++i){
            cin >> vessel[i];
            l = max(l, vessel[i]);
            r += vessel[i];
        }

        int ans = r;
        while(l <= r){
            int mid = l + ((r-l) >> 1);
            if(test(mid)){
                r = mid-1;
                ans = mid;
            }
            else{
                l = mid+1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
5 3
1 2 3 4 5
3 2
4 78 9
*/