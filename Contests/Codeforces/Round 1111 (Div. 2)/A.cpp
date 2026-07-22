#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;

        int sum = 0;
        int cur;
        while(n--){
            cin >> cur;
            sum += cur;
        }

        if(abs(sum) % 4 == 0) cout << "Yes\n";
        else cout << "No\n";
        /*
        1. (1, 1) -> 反轉後 sum -= 4
        2. (-1, -1) -> 反轉後 sum += 4
        3. (1, -1) / (-1, 1) -> 反轉後 sum += 0 -> 用途是交換1, -1的位置
        可以證明出，當sum的總合為4的倍數時 (0也是4的倍數)，就可以使得sum=0
        */
    }
    return 0;
}