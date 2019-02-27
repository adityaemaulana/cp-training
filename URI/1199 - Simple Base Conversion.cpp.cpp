#include <algorithm>
#include <math.h>
#include <iostream>
#include <cctype>
using namespace std;

typedef long long ll;

int main(){
    string s;
    while(cin >> s && s != "-1"){
        if(s.length() > 2 && s[1] == 'x')
        {
            string hex = s.substr(2, s.length()-2);
            ll decimal = 0, base = 0;

            for(int i = s.length()-1; i > 1; i--){
                ll digit = 0;
                
                if(isupper(s[i]))
                    digit = 10 + (s[i] - 'A');
                else if(islower(s[i]))
                    digit = 10 + (s[i] - 'a');
                else
                    digit = s[i] - '0';

                decimal += pow(16, base) * digit;
                base++;
            }

            cout << decimal << endl;
        }
        else
        {
            string res = "";
            ll decimal = stoi(s);
            while(decimal > 0){
                ll resd = decimal % 16;
                if(resd >= 10 && resd <= 15)
                    res += (resd - 10) + 'A';
                else
                    res += resd + '0';

                decimal /= 16;
            }

            reverse(res.begin(), res.end());
            cout << "0x" + res << endl;
        }
    }

    return 0;
}
