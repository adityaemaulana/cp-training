#include <iostream>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        int i = 0;

        for(auto &ch : s){
            if(ch == '('){ 
                if(i >= 0) i++;
            }
            if(ch == ')')
                i--;
        }

        i == 0 ? cout << "correct\n" : cout << "incorrect\n";
    }

    return 0;
}