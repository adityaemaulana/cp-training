#include <iostream>
#include <queue>
using namespace std;

int main(){
    int t;
    string a, b;
    cin >> t;

    while(t--){
        cin >> a >> b;
        queue<char> qa, qb;

        for(auto ch : a)
            qa.push(ch);
        for (auto ch : b)
            qb.push(ch);

        string res = "";
        while(!qa.empty() || !qb.empty()){
            if(!qa.empty()){
                res += qa.front(); qa.pop();
            }

            if (!qb.empty()) {
              res += qb.front(); qb.pop();
            }
        }

        cout << res << endl;
    }
    return 0;
}