#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> w(n + 1, vector<int>(n + 1));
  auto sum = w;
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= n - i + 1; j ++) {
      cin >> w[i][j];
      sum[i][j] = sum[i - 1][j] + w[i][j];
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN / 2));
  dp[0][0] = 0; // j = 0, k = 0
  for (int i = 1; i <= n; i ++) {
    for (int k = 1; k <= m; k ++) dp[0][k] = max(dp[0][k], dp[1][k]); // j = 0
    for (int j = 1; j <= min(n - i + 1, n - 1); j ++) { // j > 0
      for (int k = j; k <= m; k ++) {
        dp[j][k] = max(dp[j - 1][k - 1] + w[j][i],
                       dp[j + 1][k - j] + sum[j][i]);
      }
    }
  }
  cout << max(dp[0][m], dp[1][m]) << endl;
}