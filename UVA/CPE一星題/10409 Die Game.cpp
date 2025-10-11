#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    string cmd;
    while(cin >> n){
        if(n == 0) break;
        int top = 1, north = 2, west = 3, down = 6, south = 5, east = 4;

        while(n--){
            cin >> cmd;
            int tmp = top;
            if(cmd == "north"){
                top = south;
                south = down;
                down = north;
                north = tmp;
            }
            else if(cmd == "south"){
                top = north;
                north = down;
                down = south;
                south = tmp;
            }
            else if(cmd == "east"){
                top = west;
                west = down;
                down = east;
                east = tmp;
            }
            else if(cmd == "west"){
                top = east;
                east = down;
                down = west;
                west = tmp;
            }
        }
        cout << top << '\n';
    }
}