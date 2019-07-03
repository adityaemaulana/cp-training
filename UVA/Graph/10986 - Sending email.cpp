#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef vector<vector<pi>> vpi;

int djikstra(vpi G, int start, int stop) {
    vector<int> dist(G.size(), INT_MAX);
    dist[start] = 0; //starting point
    
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        pi front = pq.top();
        pq.pop();

        int d = front.first; int v = front.second;
        if(d > dist[v]) continue;

        for(int j = 0; j < G[v].size(); j++) {
            pi adj = G[v][j]; // adjacent vertex by v
            if(dist[v] + adj.second < dist[adj.first]) { // if not explored yet
                dist[adj.first] = dist[v] + adj.second;
                pq.push(make_pair(dist[adj.first], adj.first));
            }
        }
    }

    return dist[stop];
}

int main(){
    int N, n, m, s, t, u, v, w;
    cin >> N;

    for(int cs = 1; cs <= N; cs++) {
        cin >> n >> m >> s >> t;

        vpi G(n, vector<pi>());

        while(m--) {
            cin >> u >> v >> w;
            G[u].push_back(make_pair(v, w));
            G[v].push_back(make_pair(u, w)); 
        }

        cout << "Case #" << cs << ": ";
        int res = djikstra(G, s, t);
        if (res == INT_MAX) {
            cout << "unreachable\n";
        } else {
            cout << res << endl;
        }
        
    }
    return 0;
}
