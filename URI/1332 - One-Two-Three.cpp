#include <iostream>
using namespace std;

int main(){
    string s;
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        if(s.length() > 3)
            cout << "3\n";
        else if((s[0] == 't' && s[1] == 'w') ||
                (s[1] == 'w' && s[2] == 'o') ||
                (s[0] == 't' && s[2] == 'o'))
            cout << "2\n";
        else
            cout << "1\n";
    }

    return 0;
}