#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        vector<int> v(7);
        for(int i=0; i<7; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        int total = 0;
        for(int i=0; i<7; ++i){
            total += (i == 6 ? v[i] : -v[i]);
        }
        cout << total << '\n';
    }
    return 0;
}