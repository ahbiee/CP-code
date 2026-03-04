#include <bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2){
    int error = 0;
    for(int i=0; i<3; ++i){
        if(s1[i] != s2[i]) ++error;
    }
    return (error <= 1);
}

int main(){
    int t;
    cin >> t;
    string s;
    int count_1, count_2;
    while(t--){
        cin >> s;
        if(s.length() == 5) cout << "3\n";
        else{
            if(cmp("one", s)) cout << "1\n";
            if(cmp("two", s)) cout << "2\n";
        }
    }
    return 0;
}