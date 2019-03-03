#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll r, c, a, b, x, y;
    cin >> r >> c >> a >> b >> x >> y;
    ll xS = a + abs(b-y), yS = b + abs(b-y);
    if(a < x && ((xS >= 0 && yS >= 0 && ((xS <= x) && ((x - xS) % 2 == 0)) )))
        cout << "YA\n";
    else
        cout << "TIDAK\n";
    return 0;
}
