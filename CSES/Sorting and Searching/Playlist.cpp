#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    map<int, int> mp; // <num, lastIdx>
    for(int i=1; i<=n; ++i) cin >> v[i];

    int maxi = 1;
    for(int l = 1, r = 1; r <= n; ++r){
        // exist
        if(mp.count(v[r]) && l <= mp[v[r]]) l = mp[v[r]] + 1;
        // [IMPORTANT] avoid moving backward: l <= mp[v[r]]

        mp[v[r]] = r;
        // update
        maxi = max(maxi, r-l+1);
    }
    cout << maxi << '\n';
    return 0;
}