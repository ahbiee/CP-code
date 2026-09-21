#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    ll cur = 1, maxi = 1;
    for(int i=1; i<s.length(); ++i){
        if(s[i] == s[i-1]) ++cur;
        else cur = 1;
        maxi = max(maxi, cur);
    }
    cout << maxi << '\n';
    return 0;
}