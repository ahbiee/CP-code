#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    bool valid = true;

    cin >> n >> ws;
    while(n--){
        stack<char> st;
        string s;
        valid = true;

        getline(cin, s);
        for(char &c : s){
            if(c == '(' || c == '[' || c == '{') st.push(c);
            else if(c == ')'){
                if(!st.empty() && st.top() == '(') st.pop();
                else{
                    valid = false;
                    break;
                }
            }
            else if(c == ']'){
                if(!st.empty() && st.top() == '[') st.pop();
                else{
                    valid = false;
                    break;
                }
            }
            else if(c == '}'){
                if(!st.empty() && st.top() == '{') st.pop();
                else{
                    valid = false;
                    break;
                }
            }
        }

        cout << (valid&&st.empty() ? "Yes" : "No") << '\n';
    }
    
    return 0;
}

