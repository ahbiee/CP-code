#include <bits/stdc++.h>
using namespace std;
// a+b+c = d -> a+b = d-c
// 枚舉 a+b & d-c, 兩次 O(n^2) instead of O(n^4)

vector<int> nums;
map<int, vector<pair<int, int>>> mp;

void solve(int n){
    for(int i=n-1; i>=0; --i){
        for(int j=i-1; j>=0; --j){
            int tmp = nums[i] - nums[j];
            if(!mp.count(tmp)) continue;

            for(auto &it : mp[tmp]){
                if(i != it.first && j != it.first && i != it.second && j != it.second){
                    cout << nums[i] << '\n';
                    return;
                }
            }
        }
    }
    cout << "no solution\n";
}

int main(){
    int n;
    while(cin >> n && n){
        nums.clear();
        mp.clear();

        int num;
        for(int i=0; i<n; ++i){
            cin >> num;
            nums.push_back(num);
        }

        sort(nums.begin(), nums.end());

        // a+b
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int tmp = nums[i] + nums[j];
                if(!mp.count(tmp)) mp[tmp] = {};
                mp[tmp].push_back({i, j});
            }
        }

        // d-c
        solve(n);
    }
    return 0;
}