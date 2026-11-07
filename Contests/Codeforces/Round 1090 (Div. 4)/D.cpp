#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 10000005;
ll spf[MAXN];
vector<ll> primes;
void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) spf[i] = i, primes.push_back(i);
        for (ll p : primes) {
            if (p > spf[i] || (ll)i * p > n) break;
            spf[i * p] = p;
        }
    }
}

int main(){
    sieve(1e7);
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        for(int i=0; i<n; ++i){
            cout << primes[i] * primes[i+1] << (i == n-1 ? '\n' : ' ');
        }
    }
    return 0;
}