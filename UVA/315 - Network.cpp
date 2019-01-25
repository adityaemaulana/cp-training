#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

typedef vector<int> vi;
vector<vi> G;
vi visited, dfs_num, dfs_low, parent, articulation;
int counter, root, rootChild;

int dfs(int u){
    dfs_num[u] = dfs_low[u] = counter++;
    
    for(auto &v : G[u]){
        if(!visited[v]){
            visited[v] = 1;
            parent[v] = u;
            if(u == root) rootChild++;

            dfs(v);

            if(dfs_low[v] >= dfs_num[u])
                articulation[u] = 1;

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }else if(parent[u] != v){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main(){
    ofstream o("out.txt");
    int n, u, artNum;
    string s;
    while(cin >> n){
        if(!n) break;
        G.assign(n+1, vi()); articulation.assign(n+1, 0);
        dfs_num.assign(n+1, 0); dfs_low.assign(n+1, 0); 
        parent.assign(n+1, 0); visited.assign(n+1, 0);

        cin.ignore();
        while(getline(cin, s)){
            u = s[0] - 48;
            if(!u) break;
            for(size_t i = 2; i < s.length(); i+=2){
                G[u].push_back(s[i] - 48);
                G[s[i] - 48].push_back(u);
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
            if(articulation[i]){cout << i << " ";artNum++;} 
        cout << endl;
        o << artNum << endl;
    }
    return 0;
}