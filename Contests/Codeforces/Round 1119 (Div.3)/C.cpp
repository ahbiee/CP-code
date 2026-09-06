#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<int> v(n);
        int l1 = MAXN, r1 = -1, ln1 = MAXN, rn1 = -1; // leftmost negative 1, rightmost negative 1
        for(int i=0; i<n; ++i){
            cin >> v[i];
            if(v[i] == 1 && l1 == MAXN) l1 = i;
            if(v[i] == 1) r1 = i;

            if(v[i] == -1) rn1 = i;
            if(ln1 == MAXN && v[i] == -1) ln1 = i;
        }

        for(int i=0; i<n; ++i){
            if(v[i] == -1 && i == ln1 && ln1 < l1) v[i] = 1;
            if(v[i] == -1 && i == rn1 && rn1 > r1) v[i] = 1;
            if(v[i] == -1) v[i] = 0;

            cout << v[i] << (i == n-1 ? "\n" : " ");
        }
    }
    return 0;
}