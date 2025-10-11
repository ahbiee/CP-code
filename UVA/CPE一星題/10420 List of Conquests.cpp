#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n >> ws;
    string text;
    map<string, int> m;
    while(n--){
        getline(cin, text);
        stringstream ss(text);
        string country;
        ss >> country;
        m[country]++;
    }
    for(const auto& p : m){
        cout << p.first << " " << p.second << '\n';
    }
}
