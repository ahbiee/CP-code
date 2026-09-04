#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        int max_val = -1, max_cnt = 0;
        map<int, int> mp; // val, cnt
        int cur, total = 0;
        for(int i=0; i<n; ++i){
            cin >> cur;
            if(++mp[cur] > max_cnt){
                max_cnt = mp[cur];
                max_val = cur;
            }
            total += cur;
        }
        total -= max_val * max(0, 2 * max_cnt - n - 2);
        cout << total << '\n';
    }
    return 0;
}