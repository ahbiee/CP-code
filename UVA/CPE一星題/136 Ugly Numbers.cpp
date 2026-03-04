#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void){
    priority_queue<ll, vector<ll>, greater<ll>> pq; // the least on the top
    set<ll> s;
    pq.push(1);
    int Count = 0;
    ll num = 0;
    while(1){
        num = pq.top();
        pq.pop();
        if(!s.count(num)){
            ++Count;
            s.insert(num);
            pq.push(num*2LL);
            pq.push(num*3LL);
            pq.push(num*5LL);
        }
        if(Count == 1500) break;
    }
    cout << "The 1500'th ugly number is " << num << ".\n";

    return 0;
}