#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases;
    cin >> cases >> ws;

    while(cases--){
        map<char, int> mp;
        string text;
        getline(cin, text);
        for(int i=0; i<text.length(); ++i){
            mp[text[i]]++;
        }
        int foods[6] = {mp['M'], mp['A']/3, mp['R']/2, mp['G'], mp['I'], mp['T']};
        int min = 0x3f3f3f3f;
        for(int i=0; i<6; ++i) min = std::min(min, foods[i]);
        cout << min << '\n';
    }

    return 0;
}