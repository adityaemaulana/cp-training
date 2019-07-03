#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

class UnionFind{
private:
    vi parent, rank, isParent;

public:
    UnionFind(int n){
        isParent.assign(n, 1);
        rank.assign(n, 1);
        for(int i = 0; i < n; i++) parent.push_back(i);
    }

    int findSet(int x){
        return (parent[x] == x) ? x : findSet(parent[x]); 
    }

    bool isSameSet(int x, int y){
        return findSet(x) == findSet(y);
    }

    void link(int x, int y){
        if(!isSameSet(x, y)){
          int i = findSet(x);
          int j = findSet(y);
          if (rank[i] > rank[j]) {
            parent[j] = i;
            rank[i] += rank[j];

            isParent[i] = 1;
            isParent[j] = 0;
          } else {
            parent[i] = j;
            rank[j] += rank[i];
        
            isParent[j] = 1;
            isParent[i] = 0;
          }
        }
    }

    long long int getValidPairCount(){
        // Suppose there are n parent with its country size = p[i]
        // (p[i] * p[i+1]) + (p[i]+p[i+1] * p[i+2]) + (p[i]+..p[n-1] * p[n])

        long long int sum = 0;
        long long int count = 0;

        for(int i = 0; i < isParent.size(); i++){
            if(isParent[i]){
                count += sum * rank[i];
                sum += rank[i];    
            }
        } 
        
        return count;
    }
};
int main(){
    int a, p, u, v;
    scanf("%d%d", &a, &p);
    
    UnionFind UF(a);
    while(p--){
        scanf("%d%d", &u, &v);
        UF.link(u, v);
    }

    printf("%lld", UF.getValidPairCount());
    return 0;
}