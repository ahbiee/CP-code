#include <bits/stdc++.h>
using namespace std;

struct Register{
    int id, period, next_time;

    bool operator> (const Register& other) const{
        if(next_time != other.next_time) return next_time > other.next_time;
        return id > other.id;
    }
};

int main(){
    priority_queue<Register, vector<Register>, greater<Register>> pq;
    string s;
    vector<Register> ans;

    Register reg;
    while(cin >> s && s != "#"){
        cin >> reg.id >> reg.period;
        reg.next_time = reg.period;
        pq.push(reg);
    }

    int n;
    cin >> n;

    Register curr;
    while(n--){
        curr = pq.top();
        ans.push_back(curr);
        pq.pop();
        curr.next_time += curr.period;
        pq.push(curr);
    }

    for(Register num : ans){
        cout << num.id << '\n';
    }
    
    return 0;
}