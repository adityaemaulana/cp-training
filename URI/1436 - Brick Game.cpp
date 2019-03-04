#include <iostream>
using namespace std;

int main(){
    int t, n, x;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        int team[n];
        for(int j = 0; j < n; j++)
            cin >> team[j];
        
        cout << "Case " << i << ": " << team[n/2] << endl;
    }
    return 0;
}