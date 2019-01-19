#include <iostream>
#include <cstring>
using namespace std;

bool available[26];

int main(){
    string s;
    getline(cin ,s);
    memset(available, 0, sizeof(available));
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 65 && s[i] <= 90)  {available[s[i]-65] = 1;}
        if(s[i] >= 97 && s[i] <= 122) {available[s[i]-97] = 1;}
    }

    bool check = true;
    for(auto &i : available){
        if(!i){
            check = false;
            break;
        }   
    }

    if(check) cout << "pangram";
    else cout << "not pangram";
    return 0;
}
