#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(cin >> n){
        bool jolly = true;
        
        v.clear();
        while(!pq.empty()) pq.pop();

        while(n--){
            int num;
            cin >> num;
            v.push_back(num);
        }

        int diff;
        for(int i=0; i<v.size()-1; ++i){
            diff = abs(v[i] - v[i+1]);
            pq.push(diff);
        }

        int size = pq.size();
        for(int i=1; i <= size; ++i){
            if(pq.top() != i){
                jolly = false;
            }
            else pq.pop();
        }

        if(jolly) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}