#include <iostream>
#include <stack>
using namespace std;

int main() {
  int n, x;
  
  while(cin >> n && n){
      while(cin >> x && x){
        int query[n]; query[0] = x;
        for(int i = 1; i < n; i++)
            cin >> query[i];

        stack<int> s;
        int j = 0;
        for (int i = 1; i <= n; i++){
          s.push(i);  
          while (!s.empty() && s.top() == query[j]) {
            s.pop();
            j++;
          }
        }

        s.empty() ? cout << "Yes\n" : cout << "No\n";
      }

      cout << endl;
  }
  
  return 0;
}