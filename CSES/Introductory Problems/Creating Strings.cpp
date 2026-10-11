#include <bits/stdc++.h>
using namespace std;

string s, in;
vector<string> ans;
int cnt[26] = {};

void dfs(){
    if(s.length() == in.length()){
        ans.push_back(s);
        return;
    }
    for(int i=0; i<26; ++i){
        if(cnt[i]){
            --cnt[i];
            s.push_back(i+'a');
            dfs();
            ++cnt[i];
            s.pop_back();
        }
    }
}

int main() {
    cin >> in;
    for(char c : in) cnt[c-'a']++;
    dfs();
    cout << ans.size() << '\n';
    for(string st : ans){
        cout << st << '\n';
    }
    return 0;
}