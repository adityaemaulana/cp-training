#include <iostream>
using namespace std;

int main(){
    int t;
    double supply;

    cin >> t;
    while(t--){
        cin >> supply;
        int day = 0;
        while(supply > 1){
            supply /= 2;
            day++;
        }

        cout << day << " dias\n";
    }
    return 0;
}