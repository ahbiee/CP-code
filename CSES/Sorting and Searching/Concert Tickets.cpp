#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m){
        multiset<int> tickets;
        int tmp;
        for(int i=0; i<n; ++i){
            cin >> tmp;
            tickets.insert(tmp);
        }
        for(int i=0; i<m; ++i){
            cin >> tmp;
            auto it = tickets.upper_bound(tmp);
            if(it == tickets.begin()){
                cout << "-1\n";
            }
            else{
                cout << *(--it) << '\n';
                tickets.erase(it);
            }
        }
    }
    return 0;
}