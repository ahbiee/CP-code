#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        ll row, col;
        cin >> row >> col;
        if(row == 1 && col == 1) cout << 1;
        else if(row > col){
            if(row % 2 == 0) cout << row*row - col + 1;
            else cout << (row-1)*(row-1) + col;
        }
        else{
            if(col % 2 == 1) cout << col*col - row + 1;
            else cout << (col-1)*(col-1) + row;
        }
        cout << '\n';
    }
    return 0;
}