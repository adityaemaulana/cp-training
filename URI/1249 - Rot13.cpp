#include <iostream>
#include <cctype>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        for(auto &ch : s){
            if (islower(ch)) 
            {
                if(ch - 'a' + 13 > 25)
                    ch = 'a' + ((ch - 'a' + 13) - 26);
                else
                    ch += 13;
            }
            else if (isupper(ch)) 
            {
                if(ch - 'A' + 13 > 25)
                    ch = 'A' + ((ch - 'A' + 13) - 26);
                else
                    ch += 13;
            }
        }

        cout << s << endl;
    }
    return 0;
}
