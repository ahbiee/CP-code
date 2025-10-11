    #include <iostream>
    #include <set>
    #include <algorithm>

    using namespace std;

    int main(){
        int n;
        int cases = 0;
        while(cin >> n){
            ++cases;
            int arr[n];
            for(int i=0; i<n; ++i) cin >> arr[i];

            bool isB2 = true;

            for(int i=0; i<n; ++i){
                if(arr[i] < 1){
                    isB2 = false;
                    break;
                }
            }

            for(int i=1; i<n; ++i){
                if(arr[i] < arr[i-1]){
                    isB2 = false;
                    break;
                }
            }

            set<int> s;
            for(int i=0; i<n; ++i){
                for(int j=i; j<n; ++j){
                    int num = arr[i]+arr[j];
                    if(s.count(num)>=1){
                        isB2 = false;
                        break;
                    }
                    s.insert(num);
                }
            }
            if(isB2) cout << "Case #" << cases << ": It is a B2-Sequence.\n";
            else cout << "Case #" << cases << ": It is not a B2-Sequence.\n";
            cout << '\n';
        }
        return 0;
    }