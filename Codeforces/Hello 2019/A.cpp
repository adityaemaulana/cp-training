#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    string table, hand;
    vector<string> vs;

    cin >> table;
    for(int i = 1; i <= 5; i++){
        cin >> hand;
        vs.push_back(hand);
    }

    bool found = false;
    for(auto &s : vs){
        if(table[0] == s[0] || table[1] == s[1]){
            found = true;
            break;
        }
    }

    found ? cout<<"YES" : cout<<"NO"; 
}