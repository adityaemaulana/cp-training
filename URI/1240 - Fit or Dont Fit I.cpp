#include <iostream>
#include <math.h>
using namespace std;

typedef long long ll;

ll size(ll a){
    ll count = 0;
    while(a > 0){
        count++;
        a /= 10;
    }

    return count;
}

int main(){
    ll t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        (b == a % ll(pow(10, size(b))) ) ? cout << "encaixa\n"
                                         : cout << "nao encaixa\n";
    }
    return 0;
}