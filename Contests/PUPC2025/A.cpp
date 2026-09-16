#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    cin >> k;
    int n;
    int maxi_num, maxi_diff, curr_num;
    while(k--){
        cin >> n;
        maxi_diff = -INF;
        cin >> maxi_num;
        for(int i=2; i<=n; ++i){
            cin >> curr_num;
            maxi_diff = max(maxi_diff, maxi_num - curr_num);
            maxi_num = max(maxi_num, curr_num);
        }
        cout << maxi_diff << '\n';
    }
    return 0;
}