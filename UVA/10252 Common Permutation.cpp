#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    string a;
    string b;
    while(getline(cin, a)){
        getline(cin, b);
        map<char, int> m;
        vector<char> ans;
        int Size = a.length();
        for(int i=0; i < Size; ++i){
            ++m[a[i]];
        }
        Size = b.length();
        for(int i=0; i < Size; ++i){
            if(m[b[i]] > 0){
                ans.push_back(b[i]);
                --m[b[i]];
            }
        }
        sort(ans.begin(), ans.end());
        Size = ans.size();
        for(int i=0; i < Size; ++i){
            cout << ans[i];
        }
        cout << '\n';
    }
    
    return 0;
}