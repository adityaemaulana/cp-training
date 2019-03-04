#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n;

    while(cin >> n){
        if(!n) break;

        queue<int> q;
        vector<int> dis;

        for(int i = 1; i <= n; i++)
            q.push(i);
        
        while(q.size() > 1){
            dis.push_back(q.front()); q.pop();
            q.push(q.front()); q.pop();
        }

        cout << "Discarded cards:";
        for(int i = 0; i < dis.size(); i++){
            cout << " " << dis[i];
            if(i < dis.size() - 1)
                cout << ",";
        }

        cout << endl << "Remaining card: " << q.front() << endl;
    }
    return 0;
}