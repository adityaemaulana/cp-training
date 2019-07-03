#include <vector>   
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    vector<int> seq;
    vector<int> lucky(2);
    int t, n, a, b, val;

    cin >> t;
    while(cin >> n >> lucky[0] >> lucky[1]){
        seq.clear();
        while(n--){
            cin >> val;
            if(val % a == 0 || val % b == 0)
                seq.push_back(val);
        }
        sort(seq.begin(), seq.end(), greater<int>());

        int turn = 0;
        while(true){

            turn = 1 - turn;
        }
    }
    return 0;
}