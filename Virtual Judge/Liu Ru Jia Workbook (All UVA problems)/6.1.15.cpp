#include <bits/stdc++.h>
using namespace std;

/* 
DFS version

vector<vector<int>> arr(105);
bool visited[105];
stack<int> ans;

void dfs(int num){
    visited[num] = true;
    
    for(auto successor : arr[num]){
        if(!visited[successor]){
            dfs(successor);
        }
    }
    ans.push(num);
}

int main(){
    int m, n;
    while(cin >> m >> n && m != 0){
        arr.assign(105, vector<int>());
        memset(visited, false, sizeof(visited));

        int i, j;
        while(n--){
            cin >> i >> j;
            arr[i].push_back(j); // i precedes j
        }

        for(int i = 1; i <= m; ++i){
            if(!visited[i]) dfs(i);
        }

        bool flag = true;
        while(!ans.empty()){
            if(!flag) cout << ' ';
            flag = false;
            cout << ans.top();
            ans.pop();
        }
        cout << '\n';
    }
    
    return 0;
}
*/

// topologic version

int main(){
    int m, n;
    while(cin >> m >> n && m != 0){
        vector<vector<int>> arr(m+5);
        vector<int> inDegree(m+5, 0);

        int x, y;
        while(n--){
            cin >> x >> y;
            arr[x].push_back(y); // x precedes y
            inDegree[y]++; // indegree of y ++
        }

        queue<int> q; // free tasks
        for(int i=1; i<=m; ++i){
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for(int successor : arr[curr]){ // find successors
                inDegree[successor]--;

                if(inDegree[successor] == 0) q.push(successor);
            }
        }

        bool flag = true;
        for(auto num : ans){
            if(!flag) cout << ' ';
            flag = false;
            cout << num;
        }
        cout << '\n';
    }
    return 0;
}