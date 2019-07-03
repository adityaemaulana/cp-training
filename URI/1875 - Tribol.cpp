#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t, n;
    char u, v;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> goal(3, 0);

        while(n--){
            cin >> u >> v;

            if(u == 'R')
                v == 'G' ? goal[0] += 2 : goal[0]++;
            else if(u == 'G')
                v == 'B' ? goal[1] += 2 : goal[1]++;
            else
                v == 'R' ? goal[2] += 2 : goal[2]++;
        }
        
        vector<int> temp = goal;
        sort(temp.begin(), temp.end(), greater<int>());

        if(goal[0] == goal[1] && goal[1] == goal[2] && goal[2] == goal[0])
            cout << "trempate\n";
        else if(temp[0] == temp[1])
            cout  << "empate\n";
        else{
            if(goal[0] > goal[1] && goal[0] > goal[2])
               cout << "red\n";
            else if(goal[1] > goal[0] && goal[1] > goal[2])
                cout << "green\n";
            else
                cout << "blue\n";
        }
    }
    return 0;
}
