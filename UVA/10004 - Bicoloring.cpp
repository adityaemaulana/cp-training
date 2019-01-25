#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
vector<vi> G;
vi color;

bool bfs(){
    queue<int> Q;
    Q.push(0);
    color[0] = 0;

    while(!Q.empty()){
        int root = Q.front(); Q.pop();

        for(auto &child: G[root]){
            if(color[child] == -1){
                color[child] = 1 - color[root];
                Q.push(child);
            }else if(color[root] == color[child]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    int n, e, u, v;
    while(cin >> n){
        if(!n) break;
        G.assign(n, vi());
        color.assign(n, -1);

        cin >> e;
        while(e--){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        if(bfs()){
            cout << "BICOLORABLE." << endl;
        }else{
            cout << "NOT BICOLORABLE." << endl;
        }
    }
    return 0;
}