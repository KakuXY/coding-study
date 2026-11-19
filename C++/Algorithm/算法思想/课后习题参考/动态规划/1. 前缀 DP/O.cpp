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
    for (auto & x : line) cin >> x;
  }

  vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
  dp[0][0][0] = 0;
  pair<int, int> dir[4] = {{-1, 0}, {-1, -1}, {0, -1}, {0, 0}};
  for (int step = 1; step < n + m - 2; step ++) {
    auto &cur = dp[step & 1], &pre = dp[~step & 1];
    for (int x = max(step - m + 1, 0); x <= min(step, n - 1); x ++) {
      int y = step - x;
      for (int i = x + 1; i <= min(step, n - 1); i ++) {
        int j = step - i;
        cur[x][i] = 0;
        for (auto [dx, di] : dir) {
          int px = x + dx, pi = i + di;
          int py = step - 1 - px, pj = step - 1 - pi;
          if (px < 0 || py < 0 || pi < 0 || pj < 0) continue;
          cur[x][i] = max(cur[x][i], pre[px][pi] + w[x][y] + w[i][j]);
        }
      }
    }
  }
  cout << dp[(n + m - 3) & 1][n - 2][n - 1] << endl;
}