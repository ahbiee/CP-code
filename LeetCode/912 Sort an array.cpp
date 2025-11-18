#include <bits/stdc++.h>
using namespace std;

class MergeSort {
public:
    int arr[50005];
    int help[50005];
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        for(int i=0; i<nums.size(); ++i) arr[i] = nums[i];
        mergeSort(0, nums.size()-1);
        
        vector<int> ans;
        for(int i=0; i<nums.size(); ++i) ans.push_back(arr[i]);
        return ans;
    }

    void mergeSort(int l, int r){
        if(l == r) return; // base case
        int m = (l+r)/2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        doSort(l, m, r);
    }

    void doSort(int l, int m, int r){
        int i = l;
        int a = l;
        int b = m+1;
        while(a <= m && b <= r){
            help[i++] = (arr[a] <= arr[b]) ? arr[a++] : arr[b++];
        }
        while(a <= m){
            help[i++] = arr[a++];
        }
        while(b <= r){
            help[i++] = arr[b++];
        }
        for(int i=l; i<=r; ++i){
            arr[i] = help[i];
        }
        return;
    }
};



class QuickSort {
public:
    vector<int> arr;
    int first, last;

    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        arr = nums;
        srand(time(0));
        quickSort(0, nums.size()-1);
        return arr;
    }

    void quickSort(int l, int r){
        if(l >= r) return;
        int x = arr[l + rand()%(r-l+1)];
        partition(l, r, x);

        int left = first;
        int right = last;
        quickSort(l, left-1);
        quickSort(right+1, r);
    }

    void partition(int l, int r, int x){
        first = l;
        last = r;
        int i=l;
        while(i <= last){
            if(arr[i] < x){
                swap(first++, i++);
            }
            else if(arr[i] == x){
                ++i;
            }
            else{
                swap(last--, i);
            }
        }
    }

    void swap(int a, int b){
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
};
