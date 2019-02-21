#include <iostream>
using namespace std;

int gcd(int a, int b){
  if(a == 0)
    return b;
  return gcd(b % a, a);
}

int main(){
  int n, a, b;
  cin >> n;
  while(n--){
    cin >> a >> b;
    cout << gcd(a, b) << endl;
  }
  return 0;
}