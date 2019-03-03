#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

typedef long long ll;

string decToHex(string x){
    string hex = "";
    ll dec = stoll(x);
    while(dec > 0){
        ll resd = dec % 16;
        if(resd >= 10 && resd <= 15) 
            hex += (resd - 10) + 'a';
        else
            hex += '0' + resd;

        dec /= 16;
    }

    reverse(hex.begin(), hex.end());
    return hex;
}

string decToBin(string x){
    string bin = "";
    ll dec = stoll(x);
    while(dec > 0){
        bin += dec % 2 ? '1' : '0';
        dec /= 2;
    }

    reverse(bin.begin(), bin.end());
    return bin;
}

string binToDec(string x){
    ll dec = 0, base = 0;
    for(int i = x.length()-1; i >= 0; i--){
        dec += (x[i] - '0') * pow(2, base);
        base++;
    }

    return to_string(dec);
}

string hexToDec(string x){
    ll dec = 0, base = 0;
    for(int i = x.length()-1; i >= 0; i--){
        ll num;
        if(isupper(x[i])) num = 10 + (x[i] - 'A');
        else if(islower(x[i])) num = 10 + (x[i] - 'a');
        else num = x[i] - '0';

        dec += num * pow(16, base);
        base++;
    }

    return to_string(dec);
}
int main(){
    int t;
    string x, base;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> x >> base;
        
        cout << "Case " << i << ":\n";
        if(base == "bin")
        {
            string dec = binToDec(x);
            cout << dec << " dec\n";
            cout << decToHex(dec) << " hex\n";
        }
        else if(base == "dec")
        {
            cout << decToHex(x) << " hex\n";
            cout << decToBin(x) << " bin\n";
        }
        else
        {
            string dec = hexToDec(x);
            cout << dec << " dec\n";
            cout << decToBin(dec) << " bin\n";
        }

        cout << endl;
    }

    return 0;
}
