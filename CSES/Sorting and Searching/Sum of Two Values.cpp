#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    map<int, int> mp; // num, idx
    int cnt = 1;
    bool found = false;
    while(n--){
        int tmp;
        cin >> tmp;
        if(!found && mp.count(x - tmp)){
            cout << mp[x-tmp] << ' ' << cnt << '\n';
            found = true;
        }
        mp.insert({tmp, cnt});
        ++cnt;
    }
    if(!found) cout << "IMPOSSIBLE\n";
    return 0;
}