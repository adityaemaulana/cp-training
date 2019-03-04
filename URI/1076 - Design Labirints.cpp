#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vi> G;
vector<int> visit;
int target, count;

void dfs(int u){
    visit[u] = true;

    for(auto &v : G[u]){
        if(!visit[v]){
            count++;
            dfs(v);
            count++;
        }
    }
}

int main(){
    int t, v, a, p, q;
    cin >> t;

    while(t--){
        cin >> target >> v >> a;
        G.assign(v, vi());
        visit.assign(v, 0);

        while(a--){
            cin >> p >> q;
            G[p].push_back(q);
            G[q].push_back(p);
        }

        count = 0;
        for(int i = 0; i < v; i++){
            if(!visit[i]){
                dfs(i);
            }
        }

        cout << count << endl;
    }
    
    return 0;
}