#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int days;
    int parties;
    while(t--){
        cin >> days >> parties;
        int p[parties + 5] = {0};
        bool h[days + 5] = {false};

        for(int i=0; i<parties; ++i) cin >> p[i];

        for(int i=0; i<parties; ++i){
            int divide = 1;
            for(int j=0; j<days; ++j){
                if(p[i] == divide){
                    h[j] = true;
                    divide = 1;
                }
                else ++divide;
            }
        }

        for(int i=0; i<days; i+=7){
            h[5+i] = false;
            h[6+i] = false;
        }

        int hartals = 0;
        for(int i=0; i<days; ++i){
            if(h[i] == true){
                ++hartals;
            }
        }

        cout << hartals << '\n';
    }
    return 0;
}