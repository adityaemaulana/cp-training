#include <iostream>
#include <map>
#include <cstdio>
#include <utility>
using namespace std;

typedef long double ld;

int main(){
    int t, m, p;
    string s;
    ld x;
    cin >> t;
    while(t--){
        map<string, ld> mp;

        cin >> m;
        while(m--){
            cin >> s >> x;
            mp.insert(make_pair(s, x));
        }
            
        cin >> p;
        ld money = 0;
        while(p--){
            cin >> s >> x;
            money += mp[s] * x;
        }

        printf("R$ %.2Lf\n", money);    
    }

    return 0;
}