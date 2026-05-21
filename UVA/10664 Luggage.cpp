#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase >> ws;
    while(kase--){
        string s;
        getline(cin, s);
        stringstream ss(s);

        vector<int> v;
        int num;
        int total = 0;
        while(ss >> num){
            total += num;
            v.push_back(num);
        }

        if(total % 2){
            cout << "NO\n";
            continue;
        }

        int MAXW = total / 2;
        int dp[MAXW+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=v.size(); ++i){
            for(int j = MAXW; j >= v[i]; --j){
                dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
            }
        }
        if(dp[MAXW] == MAXW) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}