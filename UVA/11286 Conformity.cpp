#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(cin >> n && n != 0){
        map<vector<int>, int> mp; // 該組合出現的次數
        vector<int> v(5);
        for(int i=0; i<n; ++i){
            for(int j=0; j<5; ++j){
                cin >> v[j];
            }
            sort(v.begin(), v.end()); // 不管選課順序，只要同樣課程就好，所以用sort
            mp[v]++;
        }
        
        int max_num = 0; // 找出最大的數值
        for(auto &p : mp){
            max_num = max(max_num, p.second);
        }

        int total = 0;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(it->second == max_num){ // 如果最大數值有多個，要全部加總
                total += max_num;
            }
        }
        // 這邊用了兩種遍歷(pair跟iterator)，兩種方式遍歷map都是通用的

        cout << total << '\n';
    }
    
    return 0;
}

