#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

typedef vector<int> vi;
vector<vi> G;
vi visited, dfs_num, dfs_low, parent, articulation;
int counter, root, rootChild;

void dfs(int u){
    dfs_num[u] = dfs_low[u] = counter++;
    visited[u] = 1;
    
    for(auto &v : G[u]){
        if(!visited[v]){
            parent[v] = u;
            if(u == root) rootChild++;

            dfs(v);

            if(u != root && dfs_low[v] >= dfs_num[u])
                articulation[u] = 1;

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }else if(parent[u] != v){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main(){
    int n, u, v, artNum;
    while(cin >> n){
        cin.ignore();

        if(!n) break;

        G.assign(n+1, vi()); articulation.assign(n+1, 0);
        dfs_num.assign(n+1, 0); dfs_low.assign(n+1, 0); 
        parent.assign(n+1, 0); visited.assign(n+1, 0);

        string s;
        while(getline(cin, s)){
            if(s == "0") break;
            stringstream ss(s);

            ss >> u;
            while(ss >> v){
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        
        counter = 0;
        for(int i = 1; i < n+1; i++){
            if(!visited[i]){
                root = i;
                rootChild = 0;
                dfs(i);
                if(rootChild > 1) articulation[i] = 1;
            }
        }

        artNum = 0;
        for(size_t i = 1 ; i < n+1; i++)
            if(articulation[i])
                artNum++; 
        cout << artNum << endl;
    }
    return 0;
}