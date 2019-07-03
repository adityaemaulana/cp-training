#include <iostream>
#include <cstring>
#include <map>
#include <set>
using namespace std;

map<char, int> mc;
set<char> sc;

int main(){
    int q;
    string s;

    cin >> q;
    while(cin >> s){
        sc.clear();
        for (int i = 0; i < s.length(); i++)
            sc.insert(s[i]);

        for (auto &i : sc) {
          if (!mc.count(i))
            mc.insert(make_pair(i, 1));
          else
            mc[i]++;
        }
    }

    int count = 0;
    for(auto &i : mc){
        if(i.second == q) count++;
    }

    cout << count;
    return 0;
}
