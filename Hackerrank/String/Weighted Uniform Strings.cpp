#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> uniforms;

int main(){
    string s; int q;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        int count = 1;
        
        char same = s[i];
        while(i < s.length() && s[i] == same){
          uniforms.push_back(count * (s[i] - 96));
          count++;
          i++;
        }
        i--;
    }

    cin >> q;
    while(cin >> q){
        if(find(uniforms.begin(), uniforms.end(), q) != uniforms.end())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
