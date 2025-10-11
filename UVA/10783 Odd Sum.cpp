#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    int a, b;
    for(int cases = 1; cases<=t; cases++){
        cin >> a >> b;
        if(a > b) swap(a, b);
        vector<int> arr;
        for(int i=a; i<=b; ++i){
            if(i % 2 == 1) arr.push_back(i);
        }

        int sum = 0;
        for(int num : arr){
            sum += num;
        }

        cout << "Case " << cases << ": " << sum << '\n';
    }
    return 0;
}