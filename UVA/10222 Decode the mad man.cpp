#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

string words = "`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./";

int main(){
    string text;
    while(getline(cin, text)){
        vector<char> ans;
        int size = text.length();
        for(int i=0; i<size; ++i){
            if(text[i] == ' ') ans.push_back(' ');
            else{
                int index = words.find(text[i]);
                ans.push_back(words[index-2]);
            }
        }
        size = ans.size();
        for(int i=0; i<size; ++i){
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}