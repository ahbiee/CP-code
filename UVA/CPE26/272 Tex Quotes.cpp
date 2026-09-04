#include <bits/stdc++.h>
using namespace std;

int main() {
    string text;
    int cnt = 0;
    while(getline(cin, text)){
        for(int i=0; i<text.length(); ++i){
            if(text[i] == '"'){
                if(cnt++ % 2 == 0) printf("``");
                else printf("''");
            }
            else printf("%c", text[i]);
        }
        printf("\n");
    }
    return 0;
}