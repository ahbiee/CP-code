#include <iostream>

using namespace std;

int main(){
    int tasks, completed, days, counter;
    cin >> days;
    counter = 0;
    while(days--){
        cin >> tasks >> completed;
        if(completed > tasks) counter++;
    }
    cout << counter;
}