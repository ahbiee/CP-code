#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        for(char &ch : s) ch += ('*' - '1');
        cout << s << '\n';
    }
    return 0;
}