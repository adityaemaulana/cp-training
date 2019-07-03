#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<pair<int, int>, int> field;

ll run(){
    ll fences = 0;
    for(auto &f : field){
        int r = f.first.first;
        int c = f.first.second;
        fences += field.count(make_pair(r+1, c)) ? 0 : 1;
        fences += field.count(make_pair(r-1, c)) ? 0 : 1;
        fences += field.count(make_pair(r, c+1)) ? 0 : 1;
        fences += field.count(make_pair(r, c-1)) ? 0 : 1;
    }

    return fences;
}

int main(){
    int n, m, r, c, t, k;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        field.clear();
        while(k--){
            cin >> r >> c;
            field.insert(make_pair(make_pair(r, c), 1));
        }

        cout << run() << endl;
    }

    return 0;
}