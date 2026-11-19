#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

const int mod = 1e9 + 7;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<vector<int>>> dp(n + m + 1,
    vector<vector<int>>(n + 1,
      vector<int>(m + 1)));
  dp[0][0][2] = 1;
  for (int i = 0; i < n + m; i ++) {
    for (int j = 0; j <= n; j ++) {
      for (int k = 0; k <= m; k ++) {
        if (j + 1 <= n && k * 2 <= m && k) {
          dp[i + 1][j + 1][k * 2] = (dp[i + 1][j + 1][k * 2] + dp[i][j][k]) % mod;
        }
        if (k - 1 >= 0) {
          dp[i + 1][j][k - 1] = (dp[i + 1][j][k - 1] + dp[i][j][k]) % mod;
        }
      }
    }
  }
  cout << dp[n + m][n][0] << endl;
}