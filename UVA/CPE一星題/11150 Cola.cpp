#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int total = n;
        int empty = n;
        // 已喝n，剩n空瓶
        
        while(empty >= 3){ // 當我空瓶還能換
            total += empty / 3; // 我又喝掉換掉的
            empty = empty/3 + (empty%3); // 我剩下換掉後喝的 + 沒換的空瓶
        }
        if(empty == 2) ++ total; // 如果我有兩瓶空瓶就可以借

        cout << total << '\n';
    }
    return 0;
}