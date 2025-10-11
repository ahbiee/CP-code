#include <iostream>

using namespace std;

int main(){
    // 因為doomsday很難算 用1/1是禮拜六去推比較快
    int daysOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int cases;
    cin >> cases;
    while(cases--){
        int m, d;
        cin >> m >> d;
        int current_m=1, current_d=1, day = 6;
        while(current_m != m){
            day += daysOfMonth[current_m];
            ++current_m;
        }
        while(current_d != d){
            ++day;
            ++current_d;
        }
        day %= 7;
        cout << days[day] << '\n';
    }
    return 0;
}