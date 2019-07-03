#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        int res = abs((n * 63 + 7492) * 5 - 498) / 10;
        cout << res % 10  << '\n';
    }
    return 0;
}

