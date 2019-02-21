#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    int t;
    ll n;
    cin >> t;

    while(t--){
        cin >> n;
        bool prime = true;

        for(ll i = 2; i*i <= n; i++){
            if(n % i == 0){
                prime = false;
                break;
            }
        }

        prime ? cout << "Prime\n" : cout << "Not Prime\n";
    }
    return 0;
}