#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> vi;
int main(){
    int n, r;
    cin >> n;
    while(cin >> r){
        vi.push_back(r);
    }

    sort(vi.begin(), vi.end(), greater<int>());
    
    int a = 0, b = vi[0];
    
    return 0;
}