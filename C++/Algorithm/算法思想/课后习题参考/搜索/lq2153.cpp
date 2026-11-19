/**
 * 22 省赛 Java B (10/10)
 * 拉箱子
 * https://www.lanqiao.cn/problems/2153/learning
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dirs = {
  {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  auto maze = vector(n, vector(m, 0));
  for (auto &row : maze) for (auto &x : row) cin >> x;
  int ans = 0;
  auto inside = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  for (int ex = 0; ex < n; ex ++) {
    for (int ey = 0; ey < m; ey ++) {
      if (maze[ex][ey]) continue;
      auto can_reach = vector(n, vector(m, vector(n, vector(m, 0))));
      
      auto dfs = [&](auto &self, int x, int y, int bx, int by) {
        if (can_reach[x][y][bx][by]) return;
        can_reach[x][y][bx][by] = true;
        if ((x != ex || y != ey) && (bx != ex || by != ey)) ans++;
        for (auto [dx, dy] : dirs) {
          int nx = x + dx, ny = y + dy;
          if (!inside(nx, ny)) continue;
          if (maze[nx][ny]) continue;
          if (nx == bx && ny == by) {
            int nbx = bx + dx, nby = by + dy;
            if (!inside(nbx, nby)) continue;
            if (maze[nbx][nby]) continue;
            self(self, nx, ny, nbx, nby);
          } else {
            self(self, nx, ny, bx, by);
          }
        }
      };

      for (auto [dx, dy] : dirs) {
        int x = ex + dx, y = ey + dy;
        if (!inside(x, y)) continue;
        if (maze[x][y]) continue;
        dfs(dfs, x, y, ex, ey);
      }
    }
  }
  cout << ans << endl;
}