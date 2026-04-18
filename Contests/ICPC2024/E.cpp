#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    // x b b, (x+b+b)/3 = a
    while(cin >> a >> b){
        int x = 3*a - 2*b;
        printf("3\n%d %d %d\n", x, b, b);
    }
    return 0;
}