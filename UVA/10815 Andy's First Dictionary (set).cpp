// 第一次的寫法
/*
#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string text;
    set<string> table;

    while(getline(cin, text)){
        for(char &c : text){
            if(isalpha(c)) c = tolower(c);
            else c = ' ';
            // 如果是字母，轉換成小寫
            // 否則轉成空格，方便sstream操作
        }
        stringstream ss(text);
        string token;
        while(ss >> token) table.insert(token);
        // 將ss資料根據空格 insert到set中
    }
    for(const auto &s : table){
        cout << s << '\n';
        // auto迭代器輸出
    }
    return 0;
}
*/

// 第二次的寫法
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

set<string> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    char c;
    string word = "";
    while(cin.get(c)){
        if(isalpha(c)) word += tolower(c);
        else{
            if(word != "") s.insert(word);
            word = "";
        }
    }
    for(auto& str : s) cout << str << '\n';
    return 0;
}