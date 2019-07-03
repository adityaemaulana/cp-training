#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 999999
using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;

vector<vi> dist;
vector<vpi> adjList;
vector<int> parent;

int getParent(int a){
    return (parent[a] == a) ? a : getParent(parent[a]);
}

void connect(int a, int b){
    parent[getParent(a)] = getParent(b);
}

void dijkstra(int u){
    // Memorize distance from source 'u'
    dist[u].assign(adjList.size(), INF);

    dist[u][u] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push(pi(0, u));

    // Run Dijkstra
    while(!pq.empty()){
        pi front = pq.top(); pq.pop();
        int d = front.first; int U = front.second;
        
        if(d > dist[u][U])
            continue;

        for(auto &V : adjList[U]){
            int distance = (getParent(V.first) == getParent(U)) ? 
                dist[u][U] : dist[u][U] + V.second;

            if(distance < dist[u][V.first]){
                dist[u][V.first] = distance;
                pq.push(pi(distance, V.first));
            }
        }

    }
}

int main(){
    int n, e, k, u, v, w;

    while(cin >> n >> e){
        if(!n && !e)
            break;
        
        adjList.assign(n + 1, vpi());

        // Assign connection
        parent.assign(n + 1, 0);
        for(int i = 1; i < n+1; i++)
            parent[i] = i;

        while(e--){
            cin >> u >> v >> w;
            adjList[u].push_back(pi(v, w));
            
            // Check if vertices can be connected
            for(auto &V: adjList[v]){
                if(V.first == u){
                    connect(u, v);
                    break;
                }
            }
        }
        
        cin >> k;
        dist.assign(501, vi());
        
        while(k--){
            cin >> u >> v;
            
            if(dist[u].empty()){
                dijkstra(u);
            }

            dist[u][v] != INF ? cout << dist[u][v] << endl : 
                cout << "Nao e possivel entregar a carta\n";
        }

        cout << endl;
    }
    return 0;
}