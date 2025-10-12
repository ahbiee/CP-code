#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 基於kmp模板的小修改題
// 建置next的方法不動

vector<int> build_next(string pattern){
    int m = pattern.length();
    if(m == 1){
        return {-1};
    }
    vector<int> next(m);
    next[0] = -1;
    next[1] = 0;
    int i=2, cn=0;
    while(i < m){
        if(pattern[i] == pattern[cn]){
            next[i++] = ++cn;
        }
        else if(cn > 0){
            cn = next[cn];
        }
        else{
            i++;
        }
    }
    return next;
}

int kmp(string s1, string s2){
    if(s1.length() < s2.length()) return 0;

    int m = s1.length();
    int n = s2.length();
    int x=0, y=0, count=0;
    vector<int> next = build_next(s2);
    while(x < m){
        if(y == -1 || s1[x] == s2[y]){
            x++;
            y++;
        }
        else{
            y = next[y];
        }

        // 唯一新增的判斷點是這裡
        // 當我確定我找到一個same pattern之後
        // 我x已經跑到下一個位置，所以不用動x
        // 把y重製回到0，跟x繼續比對
        if(y == n){
            count++;
            y = 0;
        }
    }
    return count;
}

int main(){
    string s1, s2;
    while(cin >> s1){
        if(s1 == "#") break;
        cin >> s2;
        cout << kmp(s1, s2) << '\n';
    }
    return 0;
}