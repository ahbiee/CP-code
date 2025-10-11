#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<string, int> table;
    map<string, string> words;
    vector<string> ori_words;

    string str;

    while(cin >> str){
        if(str == "#") break;
        ori_words.push_back(str);
        
        string tmp = str;
        for(auto &s : tmp) s = tolower(s); // 將tmp全轉為小寫
        sort(tmp.begin(), tmp.end()); // 將tmp用字典序排列

        table[tmp]++; // tmp這個字母數量的元素+1
        words[str] = tmp; // str這個字會對應到tmp的字母數量
    }
    
    for(auto word : words){
        if(table[word.second] > 1) continue; 
        // 檢查table中出現超過一次的tmp字母數量，他是ananagram
        cout << word.first << '\n';
        // 不超過一次的就是nonananagram
    }
    return 0;
}