#include <bits/stdc++.h>
using namespace std;

// 1. 比對字串長度
// 2. 檢查，若有一個perfect match，那他就++
// 3. 如果沒有，暴力遍歷每個string，如果只有一個差1，他++，否則invalid

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> v;
    string name;
    for(int i=0; i<n; ++i){
        cin >> name;
        v.push_back({name, 0});
    } 

    for(int i=0; i<m; ++i){
        cin >> name;

        int found = 0;
        for(pair<string, int> &p : v){
            if(name == p.first){
                ++p.second;
                found = 1;
            }
            if(found) break;
        }
        if(found) continue;

        int diff = 0;
        string s;
        for(pair<string, int> &p : v){
            if(p.first.length() != name.length()) continue;
            diff = 0;
            for(int i=0; i<p.first.length(); ++i){
                if(p.first[i] != name[i]){
                    ++diff;
                }
            }
            if(diff == 1){
                s = p.first;
                ++found;
            }
        }
        if(found == 1){
            for(pair<string, int> &p : v){
                if(p.first == s) ++p.second;
            }
        }
    }
    for(int i=0; i<n; ++i){
        cout << v[i].second << '\n';
    }
    return 0;
}