#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t >> ws;
    string text;
    map<char, int> counts;
    map<char, double> mass;
    mass['C'] = 12.01;
    mass['O'] = 16.00;
    mass['H'] = 1.008;
    mass['N'] = 14.01;
    while(t--){
        counts.clear();
        getline(cin, text);
        int n = text.length();
        int i = 0;
        while(i < n){
            int num = 0;
            char c = text[i++];
            while(i < n && isdigit(text[i])){
                num = num*10 + (text[i] - '0');
                i++;
            }
            if(num == 0) num=1;
            counts[c] += num;
        }
        double total = 0;
        total += counts['C'] * mass['C'];
        total += counts['H'] * mass['H'];
        total += counts['O'] * mass['O'];
        total += counts['N'] * mass['N'];
        cout << fixed << setprecision(3) << total << '\n';
    }
    return 0;
}