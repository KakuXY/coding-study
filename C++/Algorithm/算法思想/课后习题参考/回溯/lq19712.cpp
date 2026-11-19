/**
 * 24 省赛 C++ B组 (6/8)
 * 数字接龙
 * https://www.lanqiao.cn/problems/19712/learning/
 */

#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dir = {
  {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  auto maze = vector(n * 2, vector(n * 2, 0));
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      cin >> maze[i * 2][j * 2];
    }
  }
  auto vis = vector(n * 2, vector(n * 2, 0));
  string ans;
  auto inside = [&](int x, int y) {
    return x >= 0 && x < n * 2 && y >= 0 && y < n * 2;
  };
  auto traceback = [&](auto &self, int x, int y) {
    // if (ans.size() == 6) {
    //   cout << ans << endl;
    // }
    if (x == n * 2 - 2 && y == n * 2 - 2) {
      if ((int)ans.size() == n * n - 1) return true;
      return false;
    }
    for (int d = 0; d < 8; d ++) {
      auto [dx, dy] = dir[d];
      int nx = x + dx, ny = y + dy;
      int nnx = nx + dx, nny = ny + dy;
      if (!inside(nnx, nny)) continue;
      if (vis[nx][ny] || vis[nnx][nny]) continue;
      if (maze[nnx][nny] != (maze[x][y] + 1) % k) continue;
      vis[nx][ny] = vis[nnx][nny] = true;
      ans += d + '0';
      if (self(self, nnx, nny)) return true;
      ans.pop_back();
      vis[nx][ny] = vis[nnx][nny] = false;
    }
    return false;
  };
  vis[0][0] = 1;
  if (maze[0][0] == 0 && traceback(traceback, 0, 0)) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}