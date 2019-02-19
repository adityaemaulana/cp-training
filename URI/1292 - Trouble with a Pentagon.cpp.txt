#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

typedef long double ld;

int main(){
    ld a;
    while(cin >> a){
        ld c = a * sin(108*M_PI/180) / sin(63*M_PI/180);
        printf("%.10Lf\n", c);
    }

    return 0;
}