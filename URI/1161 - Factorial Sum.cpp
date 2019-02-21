#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
  ll n, m;
  vector<ll> fakt{1, 1};
  for(ll i = 2; i < 21; i++)
    fakt.push_back(i * fakt[i-1]);

  while(cin >> n >> m){
    cout << fakt[n] + fakt[m] << endl;
  }
  return 0;
}