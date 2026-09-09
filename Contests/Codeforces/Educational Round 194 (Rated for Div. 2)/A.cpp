#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        int num;
        int zero_cnt = 0;
        int correct = 0;
        for(int i=0; i<n; ++i){
            cin >> num;
            if((i == 0 || i == n-1) && num == 0) correct++;
            if(num == 0) zero_cnt++;
        }
        if(zero_cnt < 2) cout << "-1\n";
        else cout << 2-correct << '\n';
    }
    return 0;
}