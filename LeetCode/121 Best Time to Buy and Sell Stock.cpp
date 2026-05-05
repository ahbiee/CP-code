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
        int diff = 0;
        for(int i=1; i<prices.size(); ++i){
            buy = min(buy, prices[i]);
            diff = max(diff, prices[i]-buy);
        }
        return diff;
    }
};