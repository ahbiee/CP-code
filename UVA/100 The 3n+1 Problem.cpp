#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int i, j;
    int count, ans;
    while(cin >> i >> j){
        cout << i << ' ' << j << ' ';
        count = ans = 0;
        if(i > j) swap(i, j);
        for(int a = i; a<=j; a++){
            int num = a;
            count = 0;
            while(num > 1){
                if(num % 2) num = num*3 + 1;
                else num /= 2;
                ++count;
            }
            ++count;
            ans = max(count, ans);
        }
        cout << ans << '\n';
    }
}