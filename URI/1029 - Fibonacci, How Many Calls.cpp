#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
  int n, x;
  vector<int> calls{0, 0, 2, 4}, fib{0, 1};

  for(int i = 2; i < 40; i++){
    fib.push_back(fib[i-1] + fib[i-2]);

    if(i > 3)
      calls.push_back(calls[i-1] + calls[i-2] + 2);
  }

  cin >> n;
  while(n--){
    cin >> x;
    printf("fib(%d) = %d calls = %d\n", x, calls[x], fib[x]);
  }
}