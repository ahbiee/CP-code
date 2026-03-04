#include <bits/stdc++.h>
using namespace std;
int main(){
    int c, n, t, m;
    // c for cases, n for loads per ferry, t for arrival time, m for m cars
    cin >> c;

    while(c--){
        cin >> n >> t >> m;

        vector<int> car_time(1445); // m < 1440
        for(int i=0; i<m; ++i){ // read array
            cin >> car_time[i];
        }

        int total_time = 0;
        int load = m % n; // we are carring [0, load) cars
        // initially, the first ferry needs to carry m % n cars, to make sure the rest ferries can carry the maximum account(n) of cars
        if(load != 0) total_time = car_time[load-1] + 2*t; // if load is 0 means we don't need to across the river for an extra

        while(load < m){
            load += n; // full compacity of ferry
            total_time = max(total_time, car_time[load-1]);
            /*
            if(total_time < car_time[load-1]) means ferry needs to wait for car,
            if(total_time > car_time[load-1]) means car needs to wait for ferry,
            if(total_time == car_time[load-1]) means ferry can go arrive immediately
            */
            total_time += 2*t;
        }

        cout << total_time - t << ' ' << ceil((double)m/(double)n) << '\n';
    }
    return 0;
}