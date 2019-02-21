#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int t = 1, n, q, val;

  while(cin >> n >> q){
    if(!n && !q)
      break;

    vector<int> M;
    while(n--){
      cin >> val;
      M.push_back(val);
    }

    sort(M.begin(), M.end());

    cout << "CASE# " << t << ":\n";

    while(q--){
      int pos;
      bool found = false;

      cin >> val;
      for(int i = 0; i < M.size(); i++){
        if(val == M[i]){
          pos = i +  1;
          found = true;
          break;
        }
      }

      if(!found)
        cout << val << " not found\n";
      else
        cout <<  val << " found at " << pos << endl;
    } 

    t++;
  }
  return 0;
}