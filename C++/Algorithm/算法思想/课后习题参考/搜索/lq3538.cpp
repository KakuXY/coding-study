/**
 * 23 省赛 Java B (6/10)
 * 合并区域
 * https://www.lanqiao.cn/problems/3538/learning
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  auto a = vector(n, vector(n, 0));
  auto b = vector(n, vector(n, 0));
  for (auto &row : a) for (auto &x : row) cin >> x;
  for (auto &row : b) for (auto &x : row) cin >> x;
  auto rotate = [&]() {
    auto c = b;
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < n; j ++) {
        c[j][n - i - 1] = b[i][j];
      }
    }
    b = c;
  };
  int ans = 0;
  auto calc = [&](int sx, int sy) {
    auto maze = vector(n * 3, vector(n * 3, 0));
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < n; j ++) {
        maze[n + i][n + j] = a[i][j];
        maze[sx + i][sy + j] = b[i][j];
      }
    }
    int cnt = 0;
    auto dfs = [&](auto &self, int x, int y) {
      if (x < 0 || x >= n * 3 || y < 0 || y >= n * 3) return;
      if (maze[x][y] == 0) return;
      cnt++;
      maze[x][y] = 0;
      self(self, x + 1, y);
      self(self, x - 1, y);
      self(self, x, y + 1);
      self(self, x, y - 1);
    };
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < n; j ++) {
        if (maze[n + i][n + j] == 1) {
          cnt = 0;
          dfs(dfs, n + i, n + j);
          ans = max(ans, cnt);
        }
        if (maze[sx + i][sy + j] == 1) {
          cnt = 0;
          dfs(dfs, sx + i, sy + j);
          ans = max(ans, cnt);
        }
      }
    }
  };
  int step = 0;
  do {
    for (int y = 1; y < n * 2 - 1; y ++) {
      calc(0, y);
      calc(n * 2, y);
    }
    for (int x = 1; x< n * 2 - 1; x ++) {
      calc(x, 0);
      calc(x, n * 2);
    }
    rotate();
  } while (++step < 4);
  cout << ans << endl;
}