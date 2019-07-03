#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int q, n;
  string s;
  char x;

  cin >> q;
  while(q--){
    ll res = 0;
    cin >> n >> s >> x;
    int currfound = -1;
    for(int i = 0; i < s.length(); i++){
      if(s[i] == x){
        res += (s.length()-i) * (i-currfound);
        currfound = i;
      }
    }

    cout << res << endl;
  }
}
