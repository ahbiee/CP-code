#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int kase;
    cin >> kase;
    ll w, b;
    while(kase--){
        ll h = 1;
        cin >> w >> b;
        while(h*(h+1)/2 <= (w+b)) ++h;
        cout << h-1 << '\n';
    }
    return 0;
}