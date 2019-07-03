#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  string s;
  while (cin >> n >> m) {
    if (!n && !m)
      break;

    cin >> s;
    vector<char> res;

    int count = 0, i = 1;

    res.push_back(s[0]);
    while(count < m){
        while(s[i] > res.back() && !res.empty() && count < m){
            res.pop_back();
            count++;
        }

        if(res.size() < (n-m))
            res.push_back(s[i]);
        else
            count++;
        
        i++;
    }
    
    while(res.size() < (n-m)){
        res.push_back(s[i]);
        i++;
    }

    for(auto &i : res) 
        cout << i;
    cout << endl;
  }

  return 0;
}
