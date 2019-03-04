#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld EPS = 1e-10;

int cmp(ld x, ld y = 0, ld tol = EPS){
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout << fixed << setprecision(4);

  long long n, a;
  ld low, hi, mid, sum;

  while (cin >> n >> a && (n + a)) {
    vector<long long> num(n);
    for (auto &i : num)
      cin >> i;

    long long total = accumulate(num.begin(), num.end(), 0LL);
    if (a == total || a == 0) {
      cout << ":D\n";
      continue;
    } else if (a > total) {
      cout << "-.-\n";
      continue;
    }

    sort(num.begin(), num.end(), greater<long long>());
    low = 0;
    hi = num[0];

    while (cmp(low, hi) == -1) {
      mid = (low + hi) * 0.5;
      sum = 0;

      for (int i = 0; i < num.size() && num[i] > mid; i++) {
        sum += num[i] - mid;
      }

      if (cmp(a, sum) == 0) {
        low = mid;
        break;
      }

      cmp(sum, a) == 1 ? low = mid : hi = mid;
    }

    cout << low + EPS << endl;
    }   
    return 0;
}

