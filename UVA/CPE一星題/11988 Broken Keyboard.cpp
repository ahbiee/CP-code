#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(getline(cin, s)){
        list<char> l;
        auto it = l.begin();
        for(char c : s){
            if(c == '[') it = l.begin();
            else if(c == ']') it = l.end();
            else l.insert(it, c); // it will automaticly point to next after insertion, we don't need to manually add ++it
        }
        for(char c : l){
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}