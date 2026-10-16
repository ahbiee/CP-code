#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tower;
    for(int i=0; i<n; ++i){
        int cur;
        cin >> cur;
        auto it = upper_bound(tower.begin(), tower.end(), cur); // tower[pos] must > cur
        if(it == tower.end()) tower.push_back(cur);
        else *it = cur; // tower[pos] = new val
    }
    cout << tower.size() << '\n';
    return 0;
}