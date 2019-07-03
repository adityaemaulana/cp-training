#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll a;
    set<ll> A;

    cin >> n;
    while(n--){
        cin >> a;
        A.insert(a);
    }    

    (A.size() > 1) ? cout << *prev(A.rbegin()) << endl : cout << 0 << endl;
}
