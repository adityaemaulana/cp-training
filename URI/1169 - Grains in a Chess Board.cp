#include <iostream>
using namespace std;

typedef unsigned long long int ll;

int main(){
    ll t, x;
    cin >> t;
    while(t--){
        cin >> x;
        ll times = 1, y = 0;

        for(int i = 0; i < x; i++){
            y += times;
            times <<= 1;
        }
        
        cout << y / 12000 << " kg" << endl;
    }

    return 0;
}