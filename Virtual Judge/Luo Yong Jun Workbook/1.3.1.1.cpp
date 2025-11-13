#include <bits/stdc++.h>
using namespace std;

/* 原寫法，沒有用到太多stack，但結構完整
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string text;
    cin >> n >> ws;
    while(n--){
        getline(cin, text);
        stringstream ss(text);
        vector<string> v;
        string word;
        while(ss >> word) v.push_back(word);

        bool first = true;
        for(string s : v){
            if(!first) cout << " ";
            first = false;

            stack<char> st;
            for(int i=0; i<s.length(); ++i) st.push(s[i]);
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
        }
        cout << '\n';
    }

    return 0;
}
*/

// 更多應用stack的寫法
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n >> ws;
    string text;
    while(n--){
        getline(cin, text);
        stack<char> st;
        char now;
        for(int i=0; i<text.length(); ++i){ // 持續讀字元直到遇到空白或換行
            now = text[i]; 
            if(now == ' ' || now == '\n'){ // 如果遇到空白或換行就先把stack裡面的輸出，直接造成reverse
                while(!st.empty()){
                    cout << st.top();
                    st.pop();
                }
                cout << ' '; // 多輸出一個空格，每個文字間原本的空格
                continue;
            }
            st.push(now); // 如果不是空行就先push到stack裡
        }
        while(!st.empty()){ // 避免stack裡面殘留(可能不會讀到'\n')，最後一次輸出
            cout << st.top();
            st.pop();
        }
        cout << '\n';
    }

    return 0;
}