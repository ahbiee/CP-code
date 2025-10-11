#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<double, double> a, b, c, d; // two of them are the same
    while(cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second){
        pair<double, double> A, B, C, ans;
        // 讓A是那個重複的點，剩下隨意
        if(a == c){
            A = a;
            B = b;
            C = d;
        }
        else if(a == d){
            A = a;
            B = b;
            C = c;
        }
        else if(b == c){
            A = b;
            B = a;
            C = d;
        }
        else{
            A = b;
            B = a;
            C = c;
        }
        // 透過向量表示法 可推得 AB向量 = B-A ， CD向量 = D-C，且因平行四邊形，兩者相等 -> D = C+B-A;
        ans.first = B.first + C.first - A.first;
        ans.second = B.second + C.second - A.second;
        cout << fixed << setprecision(3) << ans.first << ' ' << ans.second << '\n';
    }    
    return 0;
}