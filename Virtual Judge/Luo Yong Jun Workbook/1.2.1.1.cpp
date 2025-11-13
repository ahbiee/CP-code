#include <bits/stdc++.h>
using namespace std;

/* 最初的寫法，O(n+m)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n; // m for queue length, n for n words
    cin >> m >> n;

    queue<int> q, tmp;

    int check;
    int pushed = 0;
    bool found = false;

    while(n--){
        found = false;
        cin >> check;

        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
        
        if(q.empty()){
            q.push(check);
            ++pushed;
            continue;
        }

        while(!q.empty()){
            tmp.push(q.front());
            if(q.front() == check){
                found = true;
            }
            q.pop();
        }

        if(found) continue;
        
        tmp.push(check);
        if(tmp.size() > m) tmp.pop();
        pushed++;
    }

    cout << pushed << '\n';

    return 0;
}
*/

// 以下是優化寫法，使用到unordered_set的O(1)查詢，使得時間複雜度優化為O(n)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n; // m for queue length, n for n words
    cin >> m >> n;
    queue<int> q;
    unordered_set<int> s;

    int pushed = 0;

    while(n--){
        int curr;
        cin >> curr;
        if(s.count(curr)) continue;
        
        pushed++;
        if((int)q.size() == m){
            s.erase(q.front());
            q.pop();
        }

        q.push(curr);
        s.insert(curr);
    }

    cout << pushed << '\n';

    return 0;
}