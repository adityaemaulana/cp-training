#include <iostream>
#include <cstring>
using namespace std;

typedef long double ld;

int main(){
    int n;
    string a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a.length() < b.length())
            cout << "nao encaixa\n";
        else{
            if(b == a.substr(a.length()-b.length(), b.length()))
                cout << "encaixa\n";
            else
                cout << "nao encaixa\n";
        }
    }

    return 0;
}