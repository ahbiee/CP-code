#include <bits/stdc++.h>
using namespace std;

struct node{
    int x, y;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<node> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i].x >> v[i].y;
    }
    stack<node> st;
    st.push(v[0]);
    for(int i=1; i<n; ++i){ // cover when |X_i - X_j| <= Y_i - Y_j, where i is the higher one
        while(!st.empty() && abs(v[i].x - st.top().x) <= v[i].y - st.top().y) st.pop();
        if(!st.empty() && abs(st.top().x - v[i].x) <= st.top().y - v[i].y) continue;
        else st.push(v[i]);
    }
    cout << st.size() << '\n';
    return 0;
}