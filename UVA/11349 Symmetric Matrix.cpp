#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    char word;
    int s;
    for(int cases = 1; cases <= t; ++cases){
        cin >> word;
        cin >> word;
        cin >> s;
        long long arr[s][s];
        for(int i=0; i<s; ++i){
            for(int j=0; j<s; ++j){
                cin >> arr[i][j];
            }
        }

        bool symmetric = true;
        for(int i=0; i<s; ++i){
            for(int j=0; j<s; ++j){
                if(arr[i][j] < 0 || arr[i][j] != arr[s-i-1][s-j-1]){
                    symmetric = false;
                    break;
                }
            }
        }

        cout << "Test #" << cases << ": ";
        if(symmetric) cout << "Symmetric.\n";
        else cout << "Non-symmetric.\n";
    }
    return 0;
}