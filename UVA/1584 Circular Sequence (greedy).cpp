#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string str;
    string min_s, tmp_s;
    int n, size;
    cin >> n >> ws;
    for(int k=1; k<=n; ++k){
        getline(cin, str);
        size = str.size();
        str.append(str);
        min_s = str.substr(0, size);
        for(int i=0; i < size; ++i){
            tmp_s = str.substr(i, size);
            min_s = min(min_s, tmp_s);
        }
        cout << min_s << '\n';
    }
    return 0;
}