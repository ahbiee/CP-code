#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x;
    while(cin >> x >> ws){
        string s;
        getline(cin, s);
        stringstream ss(s);

        vector<int> v;
        ll num;
        while(ss >> num) v.push_back(num);

        ll ans = 0;
        for(int i=0; i<v.size()-1; ++i){
            ans = ans*x + v[i] * (v.size()-1-i); // Horner evaluation function
        }
        cout << ans << '\n';
    }
    return 0;
}