#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main(){
    vector<string> v;
    string in;
    int longest = 0;
    while(getline(cin, in)){
        v.push_back(in);
        longest = max(longest, (int)in.length());
    }

    for(int i=0; i<longest; ++i){
        for(int j=v.size()-1; j>=0; --j){
            if(i < v[j].size()) cout << v[j][i];
            else cout << ' ';
        }
        cout << '\n';
    }
}