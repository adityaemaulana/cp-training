#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

int main(){
  int n;
  string s;
  
  cin >> n;
  cin.ignore();
  while(n--){
    getline(cin, s);

    for(auto &ch : s){
      if(isalpha(ch))
        ch = ch + 3;
    }

    reverse(s.begin(), s.end());

    for(int i = s.length()/2; i < s.length(); i++)
      s[i] = s[i] - 1;
    
    cout << s << endl;
  }
  return 0;
}