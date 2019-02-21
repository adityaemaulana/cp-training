#include <iostream>
#include <algorithm>
using namespace std;

typedef long double ll;

int main() {
  int n;
  cin >> n;
  ll num[n], mx = -1;
  
  for(int i = 0; i < n; i++){
      cin >> num[i];
      mx = max(num[i], mx);
  }

  ll lbest = 0;
  for(int i = 0; i < n; i++){
      if(num[i] == mx){
          ll count = 1;

          int j = i+1;
          while(j < n && num[i] == num[j]){
              count++;
              j++;
          }

          i = j-1;
          lbest = max(lbest, count);
      }
  }

  cout << lbest << endl;

  return 0;
}
