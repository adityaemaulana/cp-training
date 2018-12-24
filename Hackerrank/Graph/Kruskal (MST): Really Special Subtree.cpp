#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
typedef vector<ppi> vpi;
vpi edges; // Edge List

class UnionFind{
private:
    vi parent, rank;
public:
    UnionFind(int n){
        rank.assign(n+1, 0);
        for(int i = 0; i <= n; i++) parent.push_back(i);
    }

    int findSet(int i){ return (parent[i] == i) ? i : findSet(parent[i]); }

    bool isSameSet(int x, int y){ return findSet(x) == findSet(y);}

    void link(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i); int y = findSet(j);
            if(rank[x] > rank[y]) 
                parent[y] = x;
            else{
                parent[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

bool comparator(ppi a, ppi b){
    return a.second < b.second;
}

int main(){
    int vx, ed, u, v, w;
    scanf("%d%d", &vx, &ed);

    UnionFind UF(vx);
    while(ed--){
        scanf("%d%d%d", &u, &v, &w);
        edges.push_back(make_pair(make_pair(u, v), w));
    }

    sort(edges.begin(), edges.end(), comparator);
    
    // Kruskal Algorithm
    int length = 0;
    for(auto &e : edges){
        int a = e.first.first;
        int b = e.first.second;
        
        if(!UF.isSameSet(a, b)){
            length += e.second;
            UF.link(a, b);
        }
    }

    printf("%d", length);
    return 0;
}