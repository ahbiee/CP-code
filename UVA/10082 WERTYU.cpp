#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char words[] = {"``1234567890-=QQWERTYUIOP[]\\AASDFGHJKL;\'ZZXCVBNM,./"};

    string text;
    while(getline(cin, text)){
        for(int i=0; i<text.length(); ++i){
            char word = text[i];
            if(word == ' '){
                cout << ' ';
                continue;
            }
            char newword;
            for(int j=0; j<52; ++j){
                if(words[j] == word){
                    newword = words[j-1];
                    break;
                }
            }
            cout << newword;
        }
        cout << '\n';
    }

    return 0;
}