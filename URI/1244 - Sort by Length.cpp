#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

struct word{
    string str;
    int pos;
};

bool comp(word a, word b){
    return a.str.length() > b.str.length() || (a.str.length() == b.str.length() && a.pos < b.pos);
}

int main(){
    int t;
    string s;
    cin >> t;
    cin.ignore();

    while(t--){
        getline(cin, s);
        stringstream iss(s);
        vector<word> vw;
        vector<int> idx;

        int i = 0;
        while(iss >> s){
            word w;
            w.str = s;
            w.pos = i;
            vw.push_back(w);

            i++;
        }

        sort(vw.begin(), vw.end(), comp);
        for(int i = 0; i < vw.size(); i++){
            cout << vw[i].str;
            if(i < vw.size()-1)
                cout << " ";
        }
        cout<<endl;
    }
    return 0;
}