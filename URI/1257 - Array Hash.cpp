#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    char c;
    cin >> t;
    while(t--){
        cin >> n;
        vector<string> elm(n);
        for(auto &i : elm) cin >> i;

        int hash = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < elm[i].length(); j++)
                hash += (elm[i][j] - 'A') + i + j; 
        }

        cout << hash << endl;
    }

    return 0;
}