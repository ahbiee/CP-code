#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        ll a, b;
        cin >> a >> b;
        ll ans = a * b;
        string s = to_string(ans);
        for(int i=0; i<s.length(); ++i){
            if(s[i] == '6') s[i] = '7';
            else if(s[i] == '7') s[i] = '6';
        }
        cout << s << '\n';
    }
       
    return 0;
}