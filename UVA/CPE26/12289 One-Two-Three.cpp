#include <bits/stdc++.h>
using namespace std;

// one two three
// o n e
// o t w
// h t e r

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        string s;
        cin >> s;
        if(s.length() == 5){
            cout << "3\n";
            continue;
        }
        int one = 0;
        if(s[0] == 'o') ++one;
        if(s[1] == 'n') ++one;
        if(s[2] == 'e') ++one;

        if(one >= 2) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}