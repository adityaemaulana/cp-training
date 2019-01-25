#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
vector<vi> G;

int main(){
    int n, rel, cases = 1;
    string s1, sp, s2;
    while(cin >> n){
        G.assign(n, vi());
        priority_queue<int, vi, greater<int>> Q;
        map<string, int> ms;
        vi in_degree(n, 0);
        vs list, beverages;

        for(int i = 0; i < n; i++){
            cin >> s1;
            ms.insert(make_pair(s1, i));
            list.push_back(s1);
        }
        cin >> rel;
        while(rel--){
            cin >> s1 >> s2;
            G[ms[s1]].push_back(ms[s2]);
        }

        // for(int i = 0; i < n; i++){
        //     cout << list[i] << ": ";
        //     for(auto &j : G[i]){
        //         cout << list[j] << " ";
        //     }
        //     cout << endl;
        // }

        // Count In-Degree
        for(int i = 0; i < n; i++){
            for(size_t j = 0; j < G[i].size(); j++)
                in_degree[G[i][j]]++;
        }   

        // Add Vertex with 0 In-Degree to queue
        for(int i = 0; i < n; i++){
            if(!in_degree[i]){
                Q.push(i);
            }
        }

        // Start search
        while(!Q.empty()){
            int x = Q.top(); Q.pop();
            beverages.push_back(list[x]);
            
            for(auto &child : G[x]){
                in_degree[child]--;
                if(in_degree[child] == 0){
                    Q.push(child);
                }
            }
        }

        cout << "Case #" << cases << ": Dilbert should drink beverages in this order:";
        for(int i = 0; i < n; i++)
            cout << " " << beverages[i];
        cout << ".\n\n";  

        cin.ignore();
        cases++;
    }
    return 0;
}