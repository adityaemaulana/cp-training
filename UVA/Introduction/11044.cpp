#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    double n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int a = ceil((n-2)/3);
        int b = ceil((m-2)/3);
        cout << a * b <<endl;
    }

    return 0;
}

