#include <map>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

map<char, int> A;
map<char, int> B;

int main(){
    string s;

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (A.count(s[i]) == 0)
        A.insert(make_pair(s[i], 1));
      else
        A[s[i]]++;
    }

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
    if (B.count(s[i]) == 0)
        B.insert(make_pair(s[i], 1));
    else
        B[s[i]]++;
    }

    int deletion = 0;
    for (auto &ch : A) {
        if(!B.count(ch.first))
            deletion += ch.second;
        else{
                if (B[ch.first] != A[ch.first]){
                  deletion += abs(B[ch.first] - A[ch.first]);
                }
            }
    }

    for(auto &ch : B){
        if(!A.count(ch.first))
            deletion += ch.second;
    }

    cout<<deletion;
}