#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

set<string> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    char c;
    string word = "";
    while(cin.get(c)){
        if(isalpha(c)) word += tolower(c);
        else{
            if(word != "") s.insert(word);
            word = "";
        }
    }
    for(auto& str : s) cout << str << '\n';
    return 0;
}