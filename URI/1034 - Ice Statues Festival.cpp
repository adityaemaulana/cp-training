#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> memo;
vector<int> block;


int main(){
  int t, n, m;
  cin >> t;
  while(t--){
    cin >> n >> m;

    memo.assign(m + 1, 0);
    block.assign(n, 0);

    for(int i = 0; i < n; i++){
      cin >> block[i];
      memo[block[i]] = 1;
    }
    
    for(int i = 2; i <= m; i++){
      if(memo[i] == 0) memo[i] = i;

      for(auto &h : block){
        if(i - h > 0){
          memo[i] = min(memo[i], memo[i - h] + 1);
        }
      }
    }

    cout << memo[m] << endl;
  }
}