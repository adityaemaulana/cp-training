#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
vector<vi> G;
vector<char> list;
vector<int> visited;
map<char , int> mc;

bool foundAns;

bool valid(int node){
    for(auto &child : G[node]){
        if(visited[child])
            return false;
    }
    return true;
}

void dfs(vi ans){
    if(ans.size() == list.size()){
        foundAns = true;
        cout << list[ans[0]];
        for(size_t i = 1; i < list.size(); i++)
            cout << " " << list[ans[i]];
        cout << endl;
        return; 
    }

    for(size_t i = 0; i < list.size(); i++){
        if(!visited[i] && valid(i)){
            visited[i] = 1;
            vi temp = ans;
            temp.push_back(i);
            dfs(temp);   
            visited[i] = 0;
        }
    }
}

int main(){
    int t; string s;
    
    cin >> t;
    cin.ignore();

    while(t--){
        cin.ignore();
        getline(cin, s);
        list.clear();

        for(auto &val : s){
            if(val != ' ')
                list.push_back(val);
        }

        sort(list.begin(), list.end());
        for(size_t i = 0; i < list.size(); i++)
            mc.insert(make_pair(list[i], i));
        
        G.assign(list.size(), vi());   
        visited.assign(list.size(), 0);
        vector<int> ans;

        getline(cin, s);
        for(size_t i = 0 ; i < s.length(); i+=4){
            G[mc[s[i]]].push_back(mc[s[i+2]]);
        }   

        foundAns = false;
        dfs(ans);

        if(!foundAns)
            cout << "NO" << endl;

        if(t > 0)
            cout << endl;    
    }

    return 0;
}