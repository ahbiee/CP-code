#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        for(int i=0; i<n; ++i) cerr << v[i] << ' ';

        int mid = n/2;
        int left = 0, right = 0;
        for(int i=0; i<mid; ++i){
            if(v[i] < v[mid]) ++left;
        }
        for(int i=mid+1; i < n; ++i){
            if(v[mid] < v[i]) ++right;
        }
        cout << max(left, right) << '\n';
    }
    return 0;
}