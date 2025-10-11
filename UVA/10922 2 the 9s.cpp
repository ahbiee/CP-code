#include <iostream>

using namespace std;

long long sum(long long n){
    long long tmp = 0;
    while(n > 0){
        tmp += n % 10;
        n /= 10;
    }
    return tmp;
}

int main(){
    string str;
    long long int num;
    int degree;

    while(cin >> str){
        if(str == "0") break;

        num = 0;
        for(int i=0; i<str.size(); ++i){
            num += str[i] - 48;
        }

        if(num%9 != 0){
            cout << str << " is not a multiple of 9.\n";
            continue;
        }

        degree = 1;
        while(num >= 10){
            num = sum(num);
            degree++;
        }

        cout << str << " is a multiple of 9 and has 9-degree " << degree << ".\n"; 
    }

    return 0;
}