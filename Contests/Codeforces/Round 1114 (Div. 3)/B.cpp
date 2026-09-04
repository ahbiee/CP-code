#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int ori = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] != s[i+1]) ori++;
        }
        
        int mini = 0;
        for (int i = 1; i < n - 1; ++i) {
            int before = (s[i-1] != s[i]) + (s[i] != s[i+1]);
            int after = (s[i-1] != s[i+1]);
            
            int diff = after - before;
            
            mini = min(mini, diff);
        }
        
        cout << ori + mini << '\n';
    }
    return 0;
}