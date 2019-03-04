#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    int t;
    int x, y;
    cin >> t;
    while(cin >> x >> y){
        int r = (3 * x) * (3 * x) + (y * y);
        int b = (2 * x * x) + (5 * y) * (5 * y);
        int c = -1 * (100 * x) + (y * y * y);

        if(b > r && b > c) 
            cout << "Beto ganhou\n";
        else if(r > b && r > c)
            cout << "Rafael ganhou\n";
        else
            cout << "Carlos ganhou\n";
    }

    return 0;
}