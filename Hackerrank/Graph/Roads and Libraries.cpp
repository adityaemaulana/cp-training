#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

class UnionFind{
private:
    vi parent, rank, isParent;
public:
    UnionFind(int n){
        rank.assign(n+1, 0);
        isParent.assign(n+1, 1);
        for(int i = 0; i <= n; i++) parent.push_back(i);
    }

    int findSet(int i){ return (parent[i] == i) ? i : findSet(parent[i]); }

    bool isSameSet(int x, int y){ return findSet(x) == findSet(y);}

    void link(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i); int y = findSet(j);
            if(rank[x] > rank[y]){ 
                parent[y] = x;
                isParent[y] = 0; isParent[x] = 1;
            }
            else{
                parent[x] = y;
                isParent[x] = 0; isParent[y] = 1;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    long long int countParent(){
        long long int count = 0;
        for(auto &i : isParent){
            if(i) count++;
        }
        return count-1;
    }
};

int main(){
    int q, m, u, v;
    long long int n, croad, clib;

    scanf("%d", &q);
    while(q--){
        scanf("%d%d%lld%lld", &n, &m, &clib, &croad);
        vector<pi> edges;
        vi isTree(n+1, 0);
        UnionFind UF(n);

        long long int costs = 0;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            if(!UF.isSameSet(u, v)){
                costs+=croad;
                UF.link(u, v);
                // printf("!issame %d %d\n", u, v);
                edges.push_back(make_pair(u, v));
                isTree[u] = 1; isTree[v] = 1;
            }
        }

        costs += UF.countParent() * clib;
        //printf("parent : %d\n", UF.countParent());

        printf("%lld\n", min(clib*n, costs));
    }
}