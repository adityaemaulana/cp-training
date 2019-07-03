#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int t, n, x;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        vector<int> H;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            H.push_back(x);
        }

        sort(H.begin(), H.end());

        for(int i = 0; i < n-1; i++){
            printf("%d ", H[i]);
        }
        printf("%d\n", H[n-1]);
    }
    return 0;
}
