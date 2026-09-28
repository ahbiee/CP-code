#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> v(n);
        for(int i=0; i<n; ++i){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int cnt = 1; // 至少一個是獨立的
        for(int i=1; i<v.size(); ++i){
            if(v[i] != v[i-1]) ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}

/*
unordered_map做法(需自訂hash function)

struct c_hash{
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return (x ^ (x >> 31));
    }
    size_t operator()(uint64_t x ) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    int n;
    while(cin >> n){
        unordered_map<int, int, c_hash> mp;
        for(int i=0; i<n; ++i){
            int tmp;
            cin >> tmp;
            mp[tmp]++;
        }
        cout << mp.size() << '\n';
    }
    return 0;
}
*/