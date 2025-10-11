#include <iostream>

using namespace std;

int main(){
    int n, m;
    bool first = true;
    int count = 1;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;

        if(first) first = false;
        else cout << '\n';

        cout << "Field #" << count << ":\n";

        char map[n][m] = {0};
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin >> map[i][j];
                if(map[i][j] == '.') map[i][j] = '0';
            }
        }


        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(map[i][j] == '*'){
                    for(int x=i-1; x<=i+1; ++x){
                        for(int y=j-1; y<=j+1; ++y){
                            if(x >= 0 && x < n && y >= 0 && y < m){
                                if(map[x][y] == '*') continue;
                                ++map[x][y];
                            }
                        }
                    }
                }
            }
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cout << map[i][j];
            }
            cout << '\n';
        }
        
        ++count;
    }
    return 0;
}