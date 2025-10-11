#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int main(){
    int n, m;

    while(cin >> n){
        if(n == 0) break;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll tmp, sum, a, b;

        sum = 0;

        for(int i=0; i<n; ++i){
            cin >> m;
            pq.push(m);
            // 把數值傳到pq 自動做排序
        }

        while(pq.size() > 1){
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            // 每次取最頂端兩個(greater，最上面最小值)

            tmp = a + b;
            sum += tmp;
            pq.push(tmp);
            // 做完相加加回去pq 再做一次排序
        }

        cout << sum << '\n';
    }
}