#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while (kase--) {
        int k;
        cin >> k;
        
        bool has_ge_3 = false; 
        int count_ge_2 = 0; 

        for (int i = 0; i < k; ++i) {
            int cnt;
            cin >> cnt;
            if (cnt >= 3) {
                has_ge_3 = true;
            }
            if (cnt >= 2) {
                count_ge_2++;
            }
        }

        if (has_ge_3 || count_ge_2 >= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}