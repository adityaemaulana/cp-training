#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, int> pii;
vector<int> parent;

bool comp(pii a, pii b){
  return a.second < b.second;
}

int getParent(int a){
  return parent[a] == a ? a : getParent(parent[a]);
}

bool isConnect(int a, int b){
  if(getParent(a) == getParent(b)) return true;
  parent[getParent(a)] = getParent(b);
  return false;
}

int main(){
  int m, n, u, v, d;
  while(cin >> m >> n){
    if(!m & !n)
      break;
    
    vector<pii> edgeList(m);
    parent.assign(m, 0);

    while(n--){
      cin >> u >> v >> d;
      edgeList.push_back(pii(pi(u, v), d));
    }

    for(int i = 0; i < m; i++)
      parent[i] = i;
    
    sort(edgeList.begin(), edgeList.end(), comp);
  
    int sum = 0;
    for(auto &e : edgeList){
      if(isConnect(e.first.second, e.first.first))
        sum += e.second;
    }

    cout << sum << endl;
  }
  return 0;
}