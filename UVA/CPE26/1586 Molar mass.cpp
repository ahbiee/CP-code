#include <bits/stdc++.h>
using namespace std;

double getMass(char c){
    if(c == 'C') return 12.010;
    if(c == 'H') return 1.008;
    if(c == 'O') return 16.000;
    if(c == 'N') return 14.010;
}

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        string s;
        cin >> s;

        double total = 0.0;
        int cnt = 0;
        
        int i=0;
        while(i < s.length()){
            double weight = getMass(s[i++]);

            while(i < s.length() && isdigit(s[i])){
                cnt = cnt*10 + (s[i]-'0');
                ++i;
            }

            if(cnt > 0){
                weight *= cnt;
                cnt = 0;
            }

            total += weight;
        }
        cout << fixed << setprecision(3) << total << '\n';
    }
    return 0;
}