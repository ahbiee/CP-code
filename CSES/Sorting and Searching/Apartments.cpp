#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    while(cin >> n >> m >> k){
        vector<int> people(n), apart(m);
        for(int i=0; i<n; ++i) cin >> people[i];
        for(int i=0; i<m; ++i) cin >> apart[i];

        sort(people.begin(), people.end());
        sort(apart.begin(), apart.end());

        int i = 0, j = 0;
        int cnt = 0;
        while(i < people.size() && j < apart.size()){
            int cur = people[i];
            int l = apart[j]-k, r = apart[j]+k;
            if(l <= cur && cur <= r){
                ++cnt;
                ++i;
                ++j;
            }
            else if(l > cur) ++i;
            else if(cur > r) ++j;
        }
        cout << cnt << '\n';
    }
    return 0;
}