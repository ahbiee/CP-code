#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sorting(vector<int> &v){
    int size = v.size();
    int count = 0;
    for(int i=0; i<size-1; ++i){
        for(int j=i; j<size; ++j){
            if(v[i] > v[j]){
                swap(v[i], v[j]);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int l;
    cin >> l;
    while(l--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; ++i){
            cin >> v[i];
        }
        int ans = sorting(v);
        cout << "Optimal train swapping takes " << ans << " swaps.\n";
    }
}