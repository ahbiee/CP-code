#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    while(cin >> s1 >> s2){
        vector<int> a(26,0), b(26,0); // 紀錄出現次數的vector
        for(char c : s1){
            ++a[c-'A'];
        }
        for(char c : s2){
            ++b[c-'A'];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        // sort兩個vector，確認出現次數的數量是否相同

        bool equals = true;
        for(int i=0; i<26; ++i){
            if(a[i] != b[i]){
                equals = false;
                break;
            }
        }
        if(equals) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}