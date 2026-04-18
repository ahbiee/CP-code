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
    vector<bool> visited;
    bool found;
    bool canReach(vector<int>& arr, int start) {
        visited.assign(arr.size(), false);
        visited[start] = true;
        found = false;
        search(arr, start);
        if(found) return true;
        return false;
    }

    void search(vector<int>& arr, int idx){
        if(arr[idx] == 0 || found){
            found = true;
            return;
        }
        if(idx + arr[idx] < arr.size() && !visited[idx + arr[idx]]){
            visited[idx + arr[idx]] = true;
            search(arr, idx+arr[idx]);
        }
        if(idx - arr[idx] >= 0 && !visited[idx - arr[idx]]){
            visited[idx - arr[idx]] = true;
            search(arr, idx-arr[idx]);
        }
    }
};