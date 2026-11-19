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
  }

  vector<vector<i64>> dp(2, vector<i64>(m + 1));
  for (int i = 0; i <= n; i ++) {
    auto &cur = dp[i % 2], &pre = dp[1 - i % 2];
    for (int j = 0; j <= m; j ++) {
      if (blocked[i][j]) cur[j] = 0;
      else if (i == 0 && j == 0) cur[j] = 1;
      else if (i == 0) cur[j] = cur[j - 1];
      else if (j == 0) cur[j] = pre[j];
      else cur[j] = pre[j] + cur[j - 1];
    }
  }
  cout << dp[n & 1][m] << endl;
}