#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int gcd(ll a, ll b){
  if(a == 0)
    return b;  
  
  return gcd(b % a, a);
}

void run(pi a, pi b, char op){
 ll N1, D1, N2, D2;
  switch(op){
    case '+':
      N1 = (a.first * b.second) + (b.first * a.second);
      D1 = (a.second * b.second);
      break;
    case '-':
      N1 = (a.first * b.second) - (b.first * a.second);
      D1 = (a.second * b.second);
      break;
    case '*':
      N1 = (a.first * b.first);
      D1 = (a.second * b.second);
      break;
    case '/':
      N1 = (a.first * b.second);
      D1 = (b.first * a.second);
      break;
    default:
      break;
  }
  ll g = gcd(abs(min(N1, D1)), abs(max(N1, D1)));
  N2 = N1 / g;
  D2 = D1 / g;

  printf("%lld/%lld = %lld/%lld\n", N1, D1, N2, D2);
}

int main(){
  int n;
  pi R1, R2;
  char op, c1, c2;
  ll N1, D1, N2, D2;

  cin >> n;
  while(n--){
    cin >> N1 >> c1 >> D1 >> op >> N2 >> c2 >> D2;
    R1 = make_pair(N1, D1);
    R2 = make_pair(N2, D2);

    run(R1, R2, op);
  }
  return 0;
}