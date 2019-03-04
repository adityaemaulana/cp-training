#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    double l, c, r1, r2, L, L1, L2;
    while(cin >> l >> c >> r1 >> r2){
        if(!l && !c && !r1 && !r2)
            break;

        double dx = l - r1 - r2, dy = c - r1 - r2;
        if(dx * dx + dy * dy >= (r1 + r2) * (r1 + r2) &&
            min(l, c) >= 2 * max(r1, r2))
            cout << "S\n";
        else
            cout << "N\n";
    }
    return 0;
}