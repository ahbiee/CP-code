#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<bool> used(n, false);
    int pairs = 0;

    queue<int> b_pos;
    for(int i=0; i<n; ++i){
        if(s[i] == 'B'){
            b_pos.push(i);
        }
        if(s[i] == 'C' && !b_pos.empty()){
            ++pairs;
            used[i] = used[b_pos.front()] = true;
            b_pos.pop();
        }
    }

    queue<int> a_pos;
    for(int i=0; i<n; ++i){
        if(used[i]) continue;
        if(s[i] == 'A'){
            a_pos.push(i);
        }
        if(s[i] == 'B' && !a_pos.empty()){
            ++pairs;
            used[i] = used[a_pos.front()] = true;
            a_pos.pop();
        }
    }

    cout << pairs << '\n';
    return 0;
}