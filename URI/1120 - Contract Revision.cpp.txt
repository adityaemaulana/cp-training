#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string num;
    char loss;

    while(cin >> loss >> num){
        if(loss == '0' && num == "0")
            break;
        
        string res = "";

        int i = 0;
        if(num[0] == loss || num[0] == '0'){
            while(i < num.length() && (num[i] == '0' || num[i] == loss))
                i++;
        }

        for(; i < num.length(); i++){
            if(i < num.length() && num[i] != loss)
                res += num[i];
        }

        !res.empty() ? cout << res << endl : cout << "0\n";
    }
    return 0;
}