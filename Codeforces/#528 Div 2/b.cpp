#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    int x = k;
    while(true){
        if(n % (x/k) == 0){
            if(x % k == (n / (x/k))){
                cout << x;
                break;
            }
        }
        x += k;
    }
    
    return 0;
}