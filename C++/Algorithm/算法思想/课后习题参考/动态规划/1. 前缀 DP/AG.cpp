#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

/**
 * 阶段：按行划分阶段
 * 状态：f(i, j) = 到 (i, j) 位置的最大值
 * 阶段间转移： f(i, j) = f(i - 1, j) + w[i][j]
 * 关键是阶段内的左右转移，可以来回走，会变成无穷大，不过有上限 k，所以一旦发现会变成无穷大，就直接把它设置为 k
 */
constexpr i64 inf = LLONG_MIN / 2;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int c, T;
  cin >> c >> T;
  while (T --) {
    int n, m, s;
    i64 k;
    cin >> n >> m >> s >> k;
    vector<vector<i64>> w(n, vector<i64>(m));
    for (auto &line : w) for (auto &x : line) cin >> x;
    vector<vector<i64>> dp(n, vector<i64>(m, inf));
    for (int i = 0; i < m; i ++) {
      dp[0][i] = min(s + w[0][i], k);
      if (dp[0][i] < 0) dp[0][i] = inf;
    }
    for (int i = 0; i < n - 1; i ++) {
      for (int j = 1; j < m; j ++) {
        if (w[i][j - 1] + w[i][j] > 0) {
          // 可以反复刷分，跳过刷分的过程，直接认为能刷满
          if (w[i][j - 1] > 0) w[i][j - 1] = k;
          if (w[i][j] > 0) w[i][j] = k;
        }
      }
      // 不断更新，直到无法松弛，其实理论上可以证明，最多更新 2 轮
      bool updated = true;
      while (updated) {
        updated = false;
        for (int j = 1; j < m; j ++) {
          i64 val = min(k, dp[i][j - 1] + w[i][j]);
          if (val < 0 || val <= dp[i][j]) continue;
          dp[i][j] = val;
          updated = true;
        }
        for (int j = m - 2; j >= 0; j --) {
          i64 val = min(k, dp[i][j + 1] + w[i][j]);
          if (val < 0 || val <= dp[i][j]) continue;
          dp[i][j] = val;
          updated = true;
        }
      }
      // 往下一阶段转移
      for (int j = 0; j < m; j ++) {
        dp[i + 1][j] = min(dp[i][j] + w[i + 1][j], k);
        if (dp[i + 1][j] < 0) dp[i + 1][j] = inf;
      }
    }
    i64 ans = inf;
    for (int i = 0; i < m; i ++) {
      ans = max(ans, dp[n - 1][i]);
    }
    if (ans < 0) cout << "-1" << endl;
    else cout << ans << endl;
  }
}