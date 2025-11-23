#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n >> ws;
    while(n--){
        string text;
        getline(cin, text);
        string mini = text; // 用mini紀錄最小的sequence
        text.append(text); // 讓text尾端重複一遍，形成circular

        int half = text.length()/2;
        for(int i=1; i<half; ++i){ // 跑一整輪找最小的sequence
            mini = min(mini, text.substr(i, half));
        }

        cout << mini << '\n';
    }
    
    return 0;
}