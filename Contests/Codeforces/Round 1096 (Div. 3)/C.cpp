#include <bits/stdc++.h>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<int> t1, t2, t3, t6;
        for(int i=0; i<n; ++i){
            int tmp;
            cin >> tmp;
            if(tmp % 6 == 0) t6.push_back(tmp);
            else if(tmp % 3 == 0) t3.push_back(tmp);
            else if(tmp % 2 == 0) t2.push_back(tmp);
            else t1.push_back(tmp);
        }

        bool first = true;
        for(int six : t6){
            if(!first) cout << ' ';
            first = false;
            cout << six;
        }

        for(int two : t2){
            if(!first) cout << ' ';
            first = false;
            cout << two;
        }

        for(int one : t1){
            if(!first) cout << ' ';
            first = false;
            cout << one;
        }

        for(int three : t3){
            if(!first) cout << ' ';
            first = false;
            cout << three;
        }
        cout << '\n';
    }
    return 0;
}