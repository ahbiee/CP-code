#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n, m;
        vector<bool> isTrue(205, false);
        cin >> n >> m;
        for(int i=0; i<m; ++i){
            int p;
            cin >> p;
            vector<int> cur;
            int idx;
            for(int j=0; j<2*p; ++j){
                cin >> idx;
                cur.push_back(idx);
            }

            char op;
            cin >> op;
            if(op == '=') for(auto &i : cur) isTrue[i] = true;
            else{
                vector<bool> appear(205, false);
                for(auto &i : cur) appear[i] = true;
                for(int i=1; i<=n; ++i){
                    if(!appear[i]) isTrue[i] = true;
                }
            }
        }
        int cnt = 0;
        int last = -1;
        for(int i=1; i<=n; ++i){
            if(isTrue[i] == false){
                ++cnt;
                last = i;
            }
            if(cnt > 1) break;
        }
        if(cnt > 1) cout << "0\n";
        else cout << last << '\n';
        if(kase) cout << '\n';
    }
    return 0;
}
/*
2

5 3
2 1 2 3 4
<
1 1 4
=
1 2 5
=

6 4
3 1 2 3 4 5 6
<
1 1 2
=
2 1 3 4 5
<
2 4 5 2 6
>
*/