#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v = {"0", "1"};
    n--;
    while(n--){
        vector<string> tmp;
        for(int i=0; i<v.size(); ++i){
            tmp.push_back("0" + v[i]);
        }
        for(int i=v.size()-1; i>=0; --i){
            tmp.push_back("1" + v[i]);
        }
        v = tmp;
    }
    for(int i=0; i<v.size(); ++i){
        cout << v[i] << '\n';
    }
    return 0;
}