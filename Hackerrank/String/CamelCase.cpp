#include <iostream>
#include <string>
using namespace std;

int main(){
    string s; cin >> s;
    int count = 1;

    for(int i = 1; i < s.length(); i++){
        if(s[i] >= 65 && s[i] <= 90)
            count++;
    }

    cout<<count;
    return 0;
}