#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    int kase;
    cin >> kase;
    while(kase--){
        string result = "";
        cin >> n;
        for(int i=1; i<=n; ++i){
            result += to_string(i);
        }
        map<char, int> mp;
        for(char i = '0'; i<='9'; ++i) 
            mp[i] = 0;

        for(char c : result)
            mp[c]++;

        bool first = true;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(!first) cout << ' ';
            first = false;
            cout << it->second;
        }
        cout << '\n';
    }
    return 0;
}