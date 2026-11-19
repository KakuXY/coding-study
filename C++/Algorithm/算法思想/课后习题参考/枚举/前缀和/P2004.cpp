#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, c;
  cin >> n >> m >> c;
  // auto maze = vector(n + 1, vector<int>(m + 1));
  // for (int i = 1; i <= n; i ++) {
  //   for (int j = 1; j <= m ; j ++) {
  //     cin >> maze[i][j];
  //   }
  // }
  auto sum = vector(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= m; j ++) {
      int x;
      cin >> x;
      sum[i][j] = x + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    }
  }
  debug(sum);
  int x = 1, y = 1, maxV = INT_MIN;
  for (int i = 0; i <= n - c; i ++) {
    for (int j = 0; j <= m - c; j ++) {
      int v = sum[i+c][j+c] - sum[i+c][j] - sum[i][j+c] + sum[i][j];
      if (v > maxV) {
        maxV = v;
        x = i + 1;
        y = j + 1;
      }
    }
  }
  cout << x << ' ' << y << endl;
}