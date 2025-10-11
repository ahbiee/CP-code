#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    string cmd, name;
    stack<string> slept;
    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == "Sleep"){
            cin >> name;
            slept.push(name);
        }
        else if(cmd == "Test"){
            if(!slept.empty()) cout << slept.top() << '\n';
            else cout << "Not in a dream\n";
        }
        else{
            if(!slept.empty()) slept.pop();
        }
    }
    return 0;
}