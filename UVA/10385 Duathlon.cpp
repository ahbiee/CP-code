#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;
double t, u[MAXN], v[MAXN];
int n;

double cal(double rd){
    double cd = t - rd;
    double ans = 1e8; 
    double TC = rd/u[n-1] + cd/v[n-1];
    for(int i=0; i<n-1; ++i){
        double tmp = rd/u[i] + cd/v[i];
        ans = min(ans, tmp-TC);
    }
    return ans;
}

int main() {
    while(cin >> t){
        cin >> n;
        for(int i=0; i<n; ++i){
            cin >> u[i] >> v[i];
        }
        double l = 0, r = t;
        for(int i=0; i<100; ++i){
            double lm = l + (r-l) / 3;
            double rm = r - (r-l) / 3;
            if(cal(lm) > cal(rm)) r = rm;
            else l = lm;
        }
        if(cal(l) < 0.00) cout << "The cheater cannot win.\n";
        else printf("The cheater can win by %.0f seconds with r = %.2lfkm and k = %.2lfkm.\n", cal(l) * 3600, l, 100-l);
    }
    return 0;
}