#include <iostream>
#include <vector>
using namespace std;

typedef long double ld;

int main(){
    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ld> grade;
        ld sum = 0;
        
        for(int i = 0; i < n; i++){
            cin >> x;
            grade.push_back(x);
            sum += x;
        }

        ld avg = sum / n, count = 0;
        for(auto &i : grade)
            if(i > avg) count++;
        
        printf("%.3Lf%\n", count / n * 100);
    }

    return 0;
}