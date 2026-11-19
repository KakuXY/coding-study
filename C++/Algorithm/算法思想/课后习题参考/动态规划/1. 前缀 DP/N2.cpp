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
  vector<vector<int>> w(n, vector<int>(m));
  for (auto & line : w) {
    for (auto &x : line) cin >> x;
  }
  const i64 inf = LLONG_MIN / 2;
  vector<array<i64, 2>> dp(n, {inf, inf});
  dp[0][0] = 0;
  for (int i = 0; i < m; i ++) {
    for (int j = 0; j < n; j ++) {
      dp[j][0] = dp[j][1] = max(dp[j][0], dp[j][1]) + w[j][i];
    }
    for (int j = 1; j < n; j ++) {
      dp[j][0] = max(dp[j][0], dp[j-1][0] + w[j][i]);
    }
    for (int j = n - 2; j >= 0; j --) {
      dp[j][1] = max(dp[j][1], dp[j+1][1] + w[j][i]);
    }
    debug(dp);
  }
  cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
}