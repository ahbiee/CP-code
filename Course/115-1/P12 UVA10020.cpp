// Greedy
#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int m;
        cin >> m;
        vector<pair<int, int>> v;

        pair<int, int> p;
        while(cin >> p.first >> p.second){
            if(p.first == 0 && p.second == 0) break;
            v.push_back(p);
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        int i = 0;
        int cur = 0;
        bool noAns = false;
        vector<pair<int, int>> ans;
        while(cur < m){
            int best = -1;
            int rmost = cur;
            while(i < v.size() && v[i].first <= cur){
                if(v[i].second > rmost){
                    rmost = v[i].second;
                    best = i;
                }
                ++i;
            }
            if(best == -1){
                noAns = true;
                break;
            }

            cur = rmost;
            ans.push_back(v[best]);
        }
        if(noAns){
            cout << "0\n\n";
            continue;
        }
        cout << ans.size() << '\n';
        for(pair<int, int> p : ans){
            cout << p.first << ' ' << p.second << '\n';
        }

        if(kase) cout << '\n'; // blank line between cases
    }
    return 0;
}

/*
2

1
-1 0
-5 -3
2 5
0 0

1
-1 0
0 1
0 0
*/