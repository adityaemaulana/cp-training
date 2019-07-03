#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int t; string s;
    cin >> t;
    cin.ignore();
    while(t--){
        getline(cin, s);

        bool found = false;
        size_t pos = s.find("not");
        if(pos != string::npos){
            if(s.length() == 3)  found = true; 
            else{
                if(pos == 0){
                    if(s[pos+3] == ' ') found = true;
                }else if(pos == s.length()-3 && s[pos-1] == ' '){
                    found = true;
                }else if(s[pos-1] == ' ' && s[pos+3] == ' '){
                    found = true;
                } 
            }
        }

        found ? cout<<"Real Fancy\n" : cout<<"regularly fancy\n";
    }
    return 0;
}