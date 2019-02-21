#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int mid = (s.length() % 2 == 0) ? s.length()/2-1 : s.length()/2;
    string out;
    out+=s[mid];

    if(s.length()%2 == 0){
        for(int i = 1; i <= mid; i++){
            out += s[mid+i];
            out += s[mid-i];
        }
        out += s[s.length()-1];
    }else{
        for(int i = 1; i <= mid; i++){
            out += s[mid+i];
            out += s[mid-i];
        }
    }

    cout << out;
    return 0;
}