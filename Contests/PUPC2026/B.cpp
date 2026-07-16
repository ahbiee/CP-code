#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    stack<char> st;
    cin >> s;
    for(int i=0; i<s.length(); ++i){
        if(!st.empty() && s[i] == st.top()) st.pop();
        else st.push(s[i]);
    }
    cout << st.size() << '\n';
    return 0;
}