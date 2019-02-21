#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ll a, b;
    cin >> a >> b;
    cout << (b * (b+1) / 2) - ((a - 1) * a / 2) << endl;
    return 0;
}