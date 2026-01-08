#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> heap;
        double sum = 0;
        for(int i=0; i<nums.size(); ++i){
            sum += nums.at(i);
            heap.push((double)nums.at(i));
        }
        sum /= 2.0; // target
        double total = 0;
        int counts = 0;
        while(total < sum){
            ++counts;
            double maxi = heap.top();
            heap.pop();
            maxi /= 2.0;
            total += maxi;
            heap.push(maxi);
        }
        return counts;
    }
};