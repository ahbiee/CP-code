#include <bits/stdc++.h>
using namespace std;

int main(){
    int kase;
    cin >> kase;
    int n;
    while(kase--){
        cin >> n;
        int cnt = 2;
        int total = cnt;
        while(total < n) total += ++cnt;
        int diff = total - n;
        if(diff == 0){
            for(int i=2; i<=cnt; ++i) cout << (i==2 ? "" : " ") << i;
        }
        else if(diff == 1){
            for(int i=3; i<cnt; ++i) cout << i << ' ';
            cout << cnt+1;
        }
        else{
            bool first = true;
            for(int i=2; i<=cnt; ++i){
                if(i == diff) continue;
                if(!first) cout << ' ';
                cout << i;
                first = false;
            }
        }
        printf("\n");
        if(kase) printf("\n");
    }
    return 0;
}