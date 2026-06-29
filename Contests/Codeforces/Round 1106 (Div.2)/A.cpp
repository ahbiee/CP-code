#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std;

/*
有兩個array
問你a有沒有辦法變成b

直覺:
sort兩個陣列
如果任意一個idx中，b>a，則不可能
若全部a>=b，則算出所有差值加總與sort的時間

有一個問題
如果原本的陣列就已經可以直接用扣的?
那我先算一遍原本的陣列用減法有沒有機會 有的話紀錄
等於一樣的事情做兩遍，就是沒sort前一遍，sort後一遍
*/

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n, c;
        cin >> n >> c;
        vector<int> a(n), b(n);
        for(int i=0; i<n; ++i) cin >> a[i];
        for(int i=0; i<n; ++i) cin >> b[i];

        // round 1: count before sorting
        bool can1 = true;
        int total1 = 0;
        for(int i=0; i<n; ++i){
            if(b[i] > a[i]) can1 = false;
            if(!can1) break;
            total1 += a[i]-b[i];
        }
        if(!can1) total1 = INF;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool can2 = true;
        int total2 = 0;
        for(int i=0; i<n; ++i){
            if(b[i] > a[i]) can2 = false;
            if(!can2) break;
            total2 += a[i]-b[i];
        }
        if(!can2) printf("-1\n");
        else printf("%d\n", min(total1, c+total2));
    }
    return 0;
}