// DFS
#include <bits/stdc++.h>
using namespace std;

int n, goal;
bool flag = false;
void dfs(int cur, int i){
    if(cur <= 0 || cur >= n+1) return;
    if(cur == goal){
        flag = true;
        return;
    }

    dfs(cur - (2*i-1), i+1);
    dfs(cur + (2*i-1), i+1);
}

int main() {
    while(cin >> n >> goal && n && goal){
        if(n >= 49){ // proved >= 49 is guaranteed to reach
            cout << "Let me try!\n";
            continue;
        }
        flag = false;

        dfs(1, 2);

        if(flag) cout << "Let me try!\n";
        else cout << "Don't make fun of me!\n";
    }
    return 0;
}