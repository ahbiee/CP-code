#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int maxi = 1;
    int cur = 1;
    for(int i=0; i<s.length()-1; ++i){
        if(s[i] == s[i+1]){
            maxi = max(maxi, ++cur);
        }
        else cur = 1;
    }   
    cout << maxi << '\n';
    return 0;
}