#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ll t, n, x, y, cap, hp;
  cin >> t;

  while (t--) {
    cin >> n;

    ll item[n + 1][2];

    for (int i = 1; i <= n; i++)
      cin >> item[i][0] >> item[i][1];

    cin >> cap >> hp;

    ll memo[n + 1][cap + 1];
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= cap; j++) {
        if (!i || !j)
          memo[i][j] = 0;
        else if (item[i][1] > j)
          memo[i][j] = memo[i - 1][j];
        else
          memo[i][j] =
              max(memo[i - 1][j - item[i][1]] + item[i][0], memo[i - 1][j]);
      }
    }

    memo[n][cap] >= hp ? cout << "Missao completada com sucesso\n"
                       : cout << "Falha na missao\n";
  }

  return 0;
}