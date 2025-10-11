#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        int total = 0;
        vector<int> v(s.size());
        if(s[0] == 'O') v[0] = 1;
        else v[0] = 0;
        for(int i=1; i<(int)s.size(); ++i){
            if(s[i] == 'O'){
                v[i] = v[i-1] + 1;
            }
            else v[i] = 0;
        }

        for(int i=0; i<(int)v.size(); ++i){
            total += v[i];
        }

        cout << total << '\n';
    }
    return 0;
}