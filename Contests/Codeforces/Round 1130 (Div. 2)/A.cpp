#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    int n, k;
    while(kase--){
        cin >> n >> k;
        vector<int> v(n);

        int lmost = -1, rmost = 105;
        int lidx = -1, ridx = -1;

        for(int i=0; i<n; ++i){
            cin >> v[i];
            if(i <= n-k && lmost < v[i]){ // 在界線之前，最大的數要往後丟
                lmost = v[i];
                lidx = i;
            }
            if(rmost > v[i] && i > (n-k)){ // 在界線之後，最小的數要往前丟
                rmost = v[i];
                ridx = i;
            }
        }
        if(lmost < rmost) cout << "-1\n";
        else cout << lidx+1 << ' ' << ridx+1 << '\n';
    }
    return 0;
}