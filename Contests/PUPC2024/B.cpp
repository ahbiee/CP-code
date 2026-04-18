#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;

struct Num{
    int ori, mod;
    Num(int ori, int mod) : ori{ori}, mod{mod} {}
    bool operator < (const Num &o) const{
        if(mod != o.mod) return mod < o.mod;
        return ori < o.ori;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m;
    string line;
    while(cin >> m >> ws){
        getline(cin, line);
        stringstream ss(line);

        vector<Num> v;
        int num;
        while(ss >>num){v.pb({num, num%m});}
        sort(v.begin(), v.end());

        for(int i=0; i<v.size(); ++i) cout << (i ? " " : "") << v[i].ori;
        cout << '\n';
    }
    return 0;
}