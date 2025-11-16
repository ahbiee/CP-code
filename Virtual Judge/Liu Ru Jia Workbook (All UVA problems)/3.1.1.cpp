#include <iostream>
#include <string>

using namespace std;

/* 原寫法，使用到vector並在完全處理完之後才輸出，可以優化
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string text;

    bool first = true;
    while(getline(cin, text)){
        vector<char> v;
        for(int i=0; i<text.length(); ++i){
            if(text[i] == '\"'){
                if(first){
                    v.push_back('`');
                    v.push_back('`');
                }
                else{
                    v.push_back('\'');
                    v.push_back('\'');
                }
                first = !first;
            }
            else{
                v.push_back(text[i]);
            }
        }
        for(char &c : v){
            cout << c;
        }
        cout << '\n';
    }


    return 0;
}
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char c;
    bool first_quote = true;

    while(cin.get(c)){
        if(c == '"'){
            if(first_quote){
                cout << "``";
            }
            else{
                cout << "\'\'";
            }
            first_quote = !first_quote;
        }
        else cout << c;
    }

    return 0;
}