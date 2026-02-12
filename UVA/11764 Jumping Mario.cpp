#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    int n;
    cin >> t;
    for(int kase = 1; kase <= t; ++kase){
        cin >> n;

        vector<int> v;
        int num;
        for(int i=0; i<n; ++i){
            cin >> num;
            v.push_back(num);
        }

        int high = 0, low = 0;
        int mario = v[0];
        for(int i=1; i<n; ++i){
            if(mario < v[i]) high++;
            else if(mario > v[i]) low++;
            // 用 v.at(i) 也可以

            mario = v[i];
        }

        cout << "Case " << kase << ": " << high << ' ' << low << '\n';
        // printf("Case %d: %d %d\n", kase, high, low);
    }
    
    return 0;
}
