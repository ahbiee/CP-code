#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        int mini = 10, tmp;
        for(int i=0; i<3; ++i){
            cin >> tmp;
            mini = min(mini, tmp);
        }
        cout << n - mini << '\n';
    }
    return 0;
}