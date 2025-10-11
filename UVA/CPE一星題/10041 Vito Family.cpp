#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int r;
    cin >> r;
    int n;
    vector<int> v;
    while(r--){
        v.clear();
        int tmp;
        cin >> n;
        for(int i=0; i<n; ++i){
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        int idx = v.size()/2;
        int total = 0;
        for(int i=0; i<v.size(); ++i){
            total += abs(v[idx] - v[i]);
        }
        cout << total << '\n';
    }
    return 0;
}