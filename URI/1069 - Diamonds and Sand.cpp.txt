#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int t;
    string s;
    cin >> t;
    cin.ignore();
    while(t--){
        getline(cin, s);
        int i = 0, count = 0;
        for(auto &ch : s){
            if(ch == '<')
                i++;
            if(ch == '>'){
                if(i > 0){ 
                    count++;
                    i--;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}