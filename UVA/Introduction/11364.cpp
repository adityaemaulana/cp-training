#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> pos(n);
        for(int i = 0; i < n; i++) 
            cin >> pos[i];
        
        sort(pos.begin(), pos.end());
        
        int dist = 0;
        for(int i = 0; i < n-1; i++)
            dist += pos[i+1]-pos[i];
        
        cout << dist * 2 << endl;
    }

    return 0;
}

