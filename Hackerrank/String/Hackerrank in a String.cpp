#include <iostream>
#include <string>
#include <queue>
using namespace std;

void initTrueQueue(queue<char> &q){
    while(!q.empty()) q.pop();

    q.push('h');
    q.push('a');
    q.push('c');
    q.push('k');
    q.push('e');
    q.push('r');
    q.push('r');
    q.push('a');
    q.push('n');
    q.push('k');
}

int main(){
    int t; cin >> t;
    queue<char> q;
    
    while(t--){
      string s;
      initTrueQueue(q);

      cin >> s;
      for (int i = 0; i < s.length(); i++) {
          if(s[i] == q.front()) q.pop();
          if(q.empty()) break;
      }
      

      if (q.empty())
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
    return 0;
}