#include <bits/stdc++.h>
using namespace std;

/*
給定一個陣列，題目要求返回在所有index處，他右側比他小的元素
如[3, 4, 9, 6, 1]，回傳陣列[1, 1, 2, 1, 0]
*/

vector<int> arr, help, ans, idx, help_idx;

void solve(int l, int m, int r);

void merge(int l, int r){
    if (l >= r) return; // l shouldn't be greater than r, and return when l == r
    
    int m = l + (r-l)/2; // prevent overflow
    merge(l, m);
    merge(m+1, r);
    solve(l, m, r);
}

void solve(int l, int m, int r){
    // count
    for(int i=l, j = m+1; i<=m; ++i){
        while(j <= r && arr[i] > arr[j]){
            j++;
        }
        ans[idx[i]] += (j-(m+1)); // total count = end - begin
    }

    // sort
    int i = l;
    int a = l;
    int b = m+1;
    while(a <= m && b <= r){
        if(arr[a] <= arr[b]){
            help_idx[i] = idx[a];
            help[i++] = arr[a++];
        }
        else{
            help_idx[i] = idx[b];
            help[i++] = arr[b++];
        }
    }
    while(a <= m){
        help_idx[i] = idx[a];
        help[i++] = arr[a++];
    }
    while(b <= r){
        help_idx[i] = idx[b];
        help[i++] = arr[b++];
    }
    for(int k=l; k <= r; ++k){
        arr[k] = help[k];
        idx[k] = help_idx[k];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; // the size of array

    while(cin >> n){
        arr.assign(n, 0);
        help.assign(n, 0);
        ans.assign(n, 0);
        idx.assign(n, 0); // idx[i] holds the original index of i (which is the value of idx[i])
        help_idx.assign(n, 0); // act like arr to help, idx to help_idx
        
        for(int i=0; i<n; ++i){
            cin >> arr[i]; // get original array from input
            idx[i] = i; // the original index of i is itself
        }

        // applying mergeSort, divide and conquer
        merge(0, n-1);

        for(int i=0; i<n; ++i){
            cout << ans[i] << (i == n-1 ? '\n' : ' ');
        }
    }
    

    return 0;
}