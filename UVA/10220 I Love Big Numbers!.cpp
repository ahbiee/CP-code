#include <iostream>
#include <vector>
#include <string>

using namespace std;

void multiply(vector<int> &v, int n){
    int carry = 0;

    for(int i=0; i<v.size(); ++i){
        int product = v[i] * n + carry;
        v[i] = product % 10;
        carry = product / 10;
    }

    while(carry > 0){
        v.push_back(carry % 10);
        carry /= 10;
    }

    return;
}

int factorial_sum(int n){
    if(n == 0) return 1;

    vector<int> v = {1};

    for(int i=2; i<=n; ++i){
        multiply(v, i);
    }

    int sum = 0;

    for(int i=0; i<v.size(); ++i){
        sum += v[i];
    }

    return sum;
}

int main(){
    int n, ans;
    while(cin >> n){
        ans = factorial_sum(n);
        cout << ans << '\n';
    }
    return 0;
}