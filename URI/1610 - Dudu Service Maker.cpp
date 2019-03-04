#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vi> G;
vi visit, vertices;

bool isCycle(int u){
    visit[u] = 1;
    vertices[u] = 1;

    for(auto &v : G[u]){

        if(!visit[v] && isCycle(v)){
            return true;
        }
        else if(vertices[v]){
            return true;
        }
    }

    vertices[u] = 0;
    return false;
}

int main(){
    int t, u, v, n, e;
    cin >> t;
    while(t--){
        cin >> n >> e;
        G.assign(n+1, vi());
        vertices.assign(n+1, 0);
        visit = vertices;

        while(e--){
            cin >> u >> v;
            G[u].push_back(v);
        }
        
        bool found = false;
        for(int i = 1; i <= n; i++){
            if(isCycle(i)){
                found = true;
                // break;
            }
        }

        found ? cout << "SIM\n" : cout << "NAO\n";  
    }
    return 0;
}