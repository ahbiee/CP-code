#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<char> r_see;

void solve(string in, string pre, int depth){
    if(in.empty() || pre.empty()) return;
    
    char ch = pre[0];
    int root = in.find(ch);

    if(depth >= r_see.size()) r_see.pb(ch);
    else r_see[depth] = ch;

    string in_pre = in.substr(0, root);
    string in_post = in.substr(root+1);

    string pre_pre = pre.substr(1, root);
    string pre_post = pre.substr(root+1);

    solve(in_pre, pre_pre, depth + 1);
    solve(in_post, pre_post, depth + 1);

    cout << ch;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int kase;
    cin >> kase;

    string in, pre;
    while(kase--){
        cin >> in >> pre;
        r_see.clear(); 

        solve(in, pre, 0); 
        cout << ' ';
        for(char &c : r_see) cout << c;
        cout << '\n';
    }
    return 0;
}