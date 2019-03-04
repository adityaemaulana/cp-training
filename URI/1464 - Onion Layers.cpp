#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

struct point{ 
    ll x, y;
    point(){ x = y = 0; }
    point(ll _x, ll _y) : x(_x), y(_y) {}
    bool operator < (const point p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator == (point other) const {
        return (x == other.x && y == other.y);
    }
};

typedef vector<point> vp;

ll cross(point o, point a, point b) {
  return ((a.x - o.x) * (b.y - o.y)) - ((a.y - o.y) * (b.x - o.x)); 
}

bool ccw(point p, point q, point r){
    return cross(p, q, r) > 0;
}

bool collinear(point p, point q, point r){
    return fabs(cross(p, q, r)) < 0;
}

point pivot;
bool angleCmp(point a, point b){
    if(collinear(pivot, a, b))
        return hypot(pivot.x - a.x, pivot.y - a.y) < hypot(pivot.x - b.x, pivot.y - b.y);
    ll d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    ll d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return atan2(d1y, d1x) < atan2(d2y, d2x);
}

vp CH(vp P){
    int i, j, n = P.size();

    int P0 = 0;
    for(i = 1; i < n; i++)
      if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
        P0 = i;

    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;

    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);

    vp S{ P[n-1], P[0], P[1] };
    i = 2;
    while(i < n){
        j = S.size()-1;
        if(ccw(S[j-1], S[j], P[i]))
            S.push_back(P[i++]);
        else
            S.pop_back();
    }
    
    return S;
}

int main(){
    int n, x, y;
    while(cin >> n && n){
        vp P;

        while(n--){
          cin >> x >> y;
          P.push_back(point(x, y));
        }

        int layer = 0, visit = 0;
        set<point> visited;
        vp next = P;
        while(next.size() != 0){
            next = CH(next);

            if(next.size() > 3)
              layer++;

            for(auto &p : next){
                visited.insert(p);
            }
            next.clear();
            for(auto &p : P)
                if(!visited.count(p))
                    next.push_back(p);
            
            
        }

        layer % 2 == 0 ? cout << "Do not take this onion to the lab!\n"
                       : cout << "Take this onion to the lab!\n";
    }
    
    return 0;
}