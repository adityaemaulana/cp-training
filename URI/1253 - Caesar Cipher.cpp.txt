#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int t, shift;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        cin >> shift;
        for(auto &c : s){
            int ch = c - 65;
            if(ch - shift < 0)
                c = 91 + (ch - shift);
            else
                c -= shift;
        }

        cout << s << endl;
    }

    return 0;
}