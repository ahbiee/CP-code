#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> arr(n+2);
        for(vector<int>& books : bookings){
            arr[books[0]] += books[2];
            arr[books[1]+1] -= books[2];
        }

        vector<int> ans;
        for(int i=1; i<n+1; ++i){ // index from 1 ~ n
            arr[i] += arr[i-1];
            ans.push_back(arr[i]);
        }
        return ans;
    }
};