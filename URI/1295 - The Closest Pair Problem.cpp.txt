#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

typedef long double lf;
typedef pair<lf, lf> pd;


int main(){
    int t;
    lf a, b, res;

    while(cin >> t){
        if(!t) break;

        vector<pd> point;
        while(t--){
            cin >> a >> b;
            point.push_back(pd(a, b));
        }

        lf res = 10000;
        for(int i = 0; i < point.size()-1; i++){
            for(int j = i+1; j < point.size(); j++){
                lf x1 = point[i].first, y1 = point[i].second, x2 = point[j].first, y2 = point[j].second;

                res = min(res, sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
            }
        }

        (res >= 10000) ? printf("INFINITY\n") : printf("%.4Lf\n", res);
    }

    return 0;
}