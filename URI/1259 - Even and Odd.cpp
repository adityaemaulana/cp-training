#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> even, odd;

int main(){
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        if(x % 2 == 1)
            odd.push_back(x);
        else
            even.push_back(x);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());

    for(auto &i : even)
        cout << i << endl;
    for(auto &i : odd)
        cout << i << endl;

    return 0;
}