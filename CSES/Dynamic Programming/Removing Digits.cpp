#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll INF = 1e18;

ll ans[(ll)1e6+5]; // 1~10^6

int main() {
    string s;
    ans[0] = 0;
    for(int i=1; i<1e6+1; ++i){
        ans[i] = INF;
        s = to_string(i);
        for(int j=1; j<=9; ++j){
            if(s.find('0' + j) != string::npos){
                ans[i] = min(ans[i], 1LL + ans[i - j]);
            }
        }
    }
    int n;
    while(cin >> n){
        cout << ans[n] << '\n';
    }
    return 0;
}