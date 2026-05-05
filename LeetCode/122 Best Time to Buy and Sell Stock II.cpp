#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int total = 0, diff = 0;
        for(int i=1; i<prices.size(); ++i){
            if(buy > prices[i] || prices[i] < prices[i-1]){
                total += diff;
                diff = 0;
                buy = prices[i];
            }
            else diff = max(diff, prices[i]-buy);
        }
        if(diff) total += diff;
        return total;
    }
};