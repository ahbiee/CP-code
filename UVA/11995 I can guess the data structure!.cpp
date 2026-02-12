#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    // 也可以用bool，但是後面判斷輸出比較麻煩
    int is_stack, is_queue, is_pq;
    int n;

    while(cin >> n){
        is_stack = is_queue = is_pq = 1;
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;

        int type, x;

        while(n--){
            cin >> type >> x;
            if(type == 1){
                st.push(x);
                q.push(x);
                pq.push(x);
            }
            else{
                // 記得要先檢查empty再做top或pop
                if(st.empty() || st.top() != x) is_stack = 0;
                else st.pop();
                if(q.empty() || q.front() != x) is_queue = 0;
                else q.pop();
                if(pq.empty() || pq.top() != x) is_pq = 0;
                else pq.pop();
            }
        }
        int total = is_stack + is_queue + is_pq;

        if(total == 0) cout << "impossible";
        else if(total > 1) cout << "not sure";
        else if(is_stack) cout << "stack";
        else if(is_queue) cout << "queue";
        else cout << "priority queue";
        cout << '\n';
    }
    
    return 0;
}
