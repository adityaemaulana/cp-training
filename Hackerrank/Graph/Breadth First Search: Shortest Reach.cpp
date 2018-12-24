#include <cstdio>
#include <vector>
#include <queue>
#define fora(i, a, b) for(i = a; i < b ; i++)
#define forb(i, v) for(i = 0; i < v.size(); i++)
using namespace std;

typedef vector<int> vi;
vector<vi> vvi;

int main(){
    int q, vertex, edge, u, v, s;
    scanf("%d", &q);
    //printf("1\n");

    while(q--){
        scanf("%d%d", &vertex, &edge);
        //printf("2\n");
        vi visited(vertex+1, 0), distances(vertex+1, -1);
        vvi.assign(vertex+1, vi());
        
        queue<int> q; 

        while(edge--){
            scanf("%d%d", &u, &v);
            //printf("3\n");
            vvi[u].push_back(v);
            vvi[v].push_back(u);
        }

        scanf("%d", &s);
        //printf("4\n");

        int i;
        visited[s] = 1;
        q.push(s);
        distances[s] = 0;

        while(!q.empty()){
            int deq = q.front(); q.pop();
            forb(i, vvi[deq]){
                int node = vvi[deq][i]; // store current node
                if(!visited[node]){
                    visited[node] = 1;
                    distances[node] = distances[deq]+6;
                    q.push(node);
                }
            }
        }

        fora(i, 1, distances.size()){
            if(i != s) printf("%d ", distances[i]);
        }
        printf("\n");
    }

    return 0;
}