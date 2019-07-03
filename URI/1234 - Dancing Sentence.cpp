#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

typedef long double ld;

int main(){
    string s;
    while(getline(cin, s)){
        int upper = 1;
        for(auto &ch : s){
            if(ch == ' ')
                continue;
            
            ch = upper ? toupper(ch) : tolower(ch);
            upper = 1 - upper;
        }

        cout << s << endl;
    }

    return 0;
}