#include <vector>
#include <cstdio>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii G;
vi visited, count, child;
int result = 0;

void dfs(int i, vi v){
    visited[i] = 1;
    
    for(auto &j : v){
        if(!visited[j]){
            count[i]++;
            dfs(j, G[j]);
            count[i]+=count[j];
        }
    }

    // Evaluate
    if(count[i] % 2 == 1)
        result++;
}

int main(){
    int v, e, p, q;
    scanf("%d %d", &v, &e);
    G.assign(v+1, vi());
    visited.assign(v+1, 0);
    count.assign(v+1, 0);
    child.assign(v+1, 0);

    while(e--){
        scanf("%d %d", &p, &q);
        G[p].push_back(q);
        G[q].push_back(p);
    }  

    for(int i = 1; i <= v; i++){
        if(!visited[i]){
            dfs(i, G[i]);
        }
    }

    printf("%d", result-1);
}