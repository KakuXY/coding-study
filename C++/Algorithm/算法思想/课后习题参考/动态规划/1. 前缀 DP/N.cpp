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
  vector<vector<array<i64, 2>>> dp(2, vector<array<i64, 2>>(n, {inf, inf}));
  dp[1][0][0] = 0;
  for (int i = 0; i < m; i ++) {
    auto &cur = dp[i & 1], &pre = dp[~i & 1];
    for (int j = 0; j < n; j ++) {
      cur[j][0] = cur[j][1] = max(pre[j][0], pre[j][1]) + w[j][i];
    }
    for (int j = 1; j < n; j ++) {
      cur[j][0] = max(cur[j][0], cur[j-1][0] + w[j][i]);
    }
    for (int j = n - 2; j >= 0; j --) {
      cur[j][1] = max(cur[j][1], cur[j+1][1] + w[j][i]);
    }
    debug(cur);
  }
  cout << max(dp[~m&1][n - 1][0], dp[~m&1][n - 1][1]) << endl;
}