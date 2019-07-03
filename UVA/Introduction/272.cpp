#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    bool found = false;
    while(getline(cin, s)) {
        for (auto &ch : s) {
            if(ch == '"') {
                if(!found) {
                    cout << "``";
                    found = true;
                } else {
                    cout << "''";
                    found = false;
                }
            } else {
                cout << ch;
            }
        }

        cout << endl;
    }
    
    return 0;
}
