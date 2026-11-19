#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  vector<vector<vector<double>>> dp(T + 1, vector<vector<double>>(T + 1, vector<double>(T + 1, 0)));
  dp[0][0][0] = 1;
  for (int i = 1; i <= T; i ++) {
    for (int j = 0; j <= i; j ++) {
      for (int k = 0; k <= i; k ++) {
        if (j) dp[i][j][k] += dp[i - 1][j - 1][k] / 3;
        if (k) dp[i][j][k] += dp[i - 1][j][k - 1] / 3;
        if (j && k) dp[i][j][k] += dp[i - 1][j - 1][k - 1] / 3;
      }
    }
  }
  double ans = 0;
  for (int i = 0; i <= T; i ++) {
    for (int j = 0; j <= T; j ++) {
      ans += dp[T][i][j] * hypot(i, j);
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}