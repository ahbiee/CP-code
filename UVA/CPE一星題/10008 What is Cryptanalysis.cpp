#include <iostream>
#include <ctype.h>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    // a[i] 存 ascii代號i 的出現次數
    int arr[128+5] = {};
    int n;
    cin >> n >> ws;
    while(n--){
        string s;
        getline(cin, s);
        for(int i=0; i<s.length(); ++i){
            if(isalpha(s[i])){
                s[i] = toupper(s[i]);
                ++arr[(int)s[i]];
            }
        }
    }
    int maxi = 0;
    for(int i=0; i<133; ++i){
        maxi = max(maxi, arr[i]);
    }
    for(int i=maxi; i>=1; --i){
        for(int j=0; j<133; ++j){
            if(arr[j] == i) cout << (char)j << ' ' << i << '\n';
        }
    }
    return 0;
}