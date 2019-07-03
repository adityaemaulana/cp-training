#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, val, t=1;
    while(cin >> n && n) {
        a = b = 0;
        while(n--) {
            cin >> val;
            if(!val) b++;
            else a++;
        }

        cout << "Case " << t++ << ": " << (a - b) << '\n';
    }
    return 0;
}

