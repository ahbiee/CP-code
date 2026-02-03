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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int Size = gas.size();

        for(int l=0, r=0, sum; l < Size; l = r+1, r=l){
            sum = 0;
            while(sum + gas[r%Size] - cost[r%Size] >= 0){
                if(r-l+1 == Size) return l;
                sum += gas[r%Size] - cost[r%Size];
                ++r;
            }
        }
        return -1;
    }
};