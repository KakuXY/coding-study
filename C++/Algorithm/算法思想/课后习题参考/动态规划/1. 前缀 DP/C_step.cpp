#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  pair<int, int> dirs[] = {
    {-1, -2}, {-1, 2}, {-2, -1}, {-2, 1},
    {1, -2}, {1, 2}, {2, -1}, {2, 1}
  };
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<vector<int>> blocked(n + 1, vector<int>(m + 1));
  blocked[x][y] = 1;
  for (auto [dx, dy] : dirs) {
    int nx = x + dx, ny = y + dy;
    if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
    blocked[nx][ny] = 1;
  };

  vector<vector<i64>> dp(2, vector<i64>(n + 1));
  dp[0][0] = 1;
  for (int step = 1; step <= n + m; step ++) {
    auto &cur = dp[step & 1], &pre = dp[~step & 1];
    for (int i = max(0, step - m); i <= min(step, n); i ++) {
      cur[i] = 0;
      if (blocked[i][step - i]) continue;
      cur[i] += pre[i];
      if (i) cur[i] += pre[i - 1];
    }
  }
  cout << dp[(n + m) & 1][n] << endl;
}