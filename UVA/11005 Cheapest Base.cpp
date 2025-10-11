#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    bool first = true;
    for(int cases = 1; cases <= n; ++cases){
        if(!first) cout << '\n';
        else first = false;
        cout << "Case " << cases << ":\n";

        vector<int> cost;
        int costtmp;
        for(int i=0; i<36; ++i){
            cin >> costtmp;
            cost.push_back(costtmp);
        }

        vector<int> cheapest;
        int q;
        cin >> q;
        // Y個輸入數字，將這個數字用各個base做mod得到餘數，然後除base直到Y=0，加總的所有餘數=base的cost
        int num;
        int mini;
        int sum;
        while(q--){
            cheapest.clear();
            mini = 0x3f3f3f3f;
            cin >> num;
            for(int i=2; i<=36; ++i){
                sum = 0;
                int tmp = num;
                while(tmp > 0){
                    int digit = tmp % i;
                    sum += cost[digit];
                    tmp /= i;
                }
                if(sum < mini){
                    cheapest.clear();
                    cheapest.push_back(i);
                    mini = sum;
                }
                else if(sum == mini) cheapest.push_back(i);
            }   

            cout << "Cheapest base(s) for number " << num << ":";
            for(int cheap : cheapest){
                cout << ' ' << cheap;
            }
            cout << '\n';
        }
    }
    
    return 0;
}