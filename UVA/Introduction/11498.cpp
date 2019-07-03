#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, x, y, p, q;

    while(cin >> k && k) {
        cin >> x >> y;
        while(k--) {
            cin >> p >> q;

            int xdif = p - x;
            int ydif = q - y;

            if (!xdif || !ydif)
                cout << "divisa";
            else if (xdif < 0 && ydif > 0)
                cout << "NO";
            else if (xdif > 0 && ydif > 0)
                cout << "NE";
            else if (xdif > 0 && ydif < 0)
                cout << "SE";
            else
                cout << "SO";
            
            cout << '\n';
        }
    }
    return 0;
}

