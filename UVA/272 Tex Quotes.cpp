#include <iostream>
#include <string>

using namespace std;

int main(){
    string text;
    bool left = true;
    while(getline(cin, text)){
        string ans;
        for(char c : text){ // 遍歷字串，如果是 " 就根據是左還是右判斷在ans加上哪個，否則加原本的字元
            if(c == '"'){
                if(left){
                    ans += "``";
                    left = false;
                }
                else{
                    ans += "\'\'";
                    left = true;
                }
            }
            else ans += c;
        }
        cout << ans << '\n';
    }
    return 0;
}