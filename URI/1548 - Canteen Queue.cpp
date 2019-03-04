#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long double ld;

int main(){
    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        priority_queue<int> pq;
        vector<int> v;
        while(n--){
            cin >> x;
            pq.push(x); v.push_back(x);
        }

        int i = 0, count = 0;
        while(!pq.empty()){
            if(pq.top() == v[i]) count++;

            pq.pop();
            i++;
        }

        cout << count << endl;
    }

    return 0;
}