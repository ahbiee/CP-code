#include <iostream>
#include <vector>

using namespace std;

int main(){
    int num;
    int div;
    while(cin >> num >> div){
        // 注意num或div為非負整數，可以為0或1，都要輸出Boring
        if(num <= 1 || div <= 1){
            cout << "Boring!\n";
            continue;
        }
        vector<int> ans;
        ans.push_back(num);
        bool boring = false;

        while(num > 1){
            if(num % div == 0){
                num /= div;
                ans.push_back(num);
            }
            else{
                boring = true;
                break;
            }
        }
        if(boring) cout << "Boring!\n";
        else{
            bool first = true;
            for(int n : ans){
                if(first) first = false;
                else cout << ' ';
                cout << n;
            }
            cout << '\n';
        }
    }
}