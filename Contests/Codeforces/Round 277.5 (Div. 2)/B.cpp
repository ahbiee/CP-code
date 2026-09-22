#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while(cin >> n){
        vector<int> boy(n);
        for(int i=0; i<n; ++i) cin >> boy[i];
        cin >> m;
        vector<int> girl(m);
        for(int i=0; i<m; ++i) cin >> girl[i];

        sort(boy.begin(), boy.end());
        sort(girl.begin(), girl.end());

        int i=0, j=0;
        int cnt = 0;
        while(i < n && j < m){
            if(abs(boy[i] - girl[j]) <= 1){
                ++cnt;
                ++i;
                ++j;
            }
            else if(boy[i] > girl[j]) ++j;
            else ++i;
        }
        cout << cnt << '\n';
    }
    return 0;
}