#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int s;
    cin >> s;
    while(s--){
        int n, i;
        double p;
        cin >> n >> p >> i;
        if(p == 0.0){
            cout << fixed << setprecision(4) << 0.0 << '\n';
            continue;
        }

        double a = p * pow(1-p, i-1);
        double b = 1 - pow(1-p, n);
        cout << fixed << setprecision(4) << a/b << '\n';
    }
    return 0;
}