#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// https://www.nowcoder.com/practice/36fb0fd3c656480c92b569258a1223d5
#define MAXN 100005

int arr[MAXN];
int n, k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> k){
        for(int i=0; i<n; ++i){
            cin >> arr[i];
        }

        map<int, int> mp; // <prefixSum, firstIndex>
        mp.clear();
        mp.insert({0, -1});

        int sum = 0;
        int ans = 0;
        for(int i=0; i<n; ++i){
            sum += arr[i]; // 記錄截至目前為止的前綴和
            if(mp.count(sum-k)){
                ans = max(ans, i - mp[sum-k]);
            }
            if(mp.count(sum) == 0)
                mp[sum] = i;
        }
        cout << ans << '\n';
    }
    return 0;
}