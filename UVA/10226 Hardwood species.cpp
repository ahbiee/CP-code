#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases;
    cin >> cases;
    cin.ignore();
    cin.ignore();
    for(int t=0; t<cases; ++t){
        map<string, int> m;
        string text;
        vector<string> woods;
        int total = 0;
        while(getline(cin, text)){
            if(text.empty()) break;
            ++m[text];
            ++total;
        }
        for(auto &p : m){
            cout << p.first << ' ' << fixed << setprecision(4) << double(p.second)/double(total)*100 << '\n';
        }
        if(t != cases-1) cout << '\n'; // case之間要有空行
    }
    return 0;
}