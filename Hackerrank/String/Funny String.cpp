#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

vector<int> a, b;

int main(){
    int q;
    string s;
    
    cin >> q;
    while(cin >> s){
        a.clear();
        b.clear();
        for(int i = 0; i < s.length()-1; i++)
            a.push_back(abs(s[i] - s[i+1]));

        for(int i = s.length()-1; i > 0; i--)
            b.push_back(abs(s[i]-s[i-1]));

        (a == b) ? cout << "Funny\n" : cout << "Not Funny\n";
    }

    return 0;
}
