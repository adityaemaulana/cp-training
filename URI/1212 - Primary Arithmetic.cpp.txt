#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ll a, b;
    while(cin >> a >> b && (a + b)){
        int count = 0, carry = 0;
        while(a > 0 || b > 0){
            if((a % 10) + (b % 10) + carry > 9){
                carry = 1;
                count++;
            }else{
                carry = 0;
            }

            a /= 10; b /= 10;
        }

        if(!count) cout << "No carry operation.\n";
        else if(count > 1) cout << count << " carry operations.\n";
        else cout << "1 carry operation.\n";
    }
    return 0;
}