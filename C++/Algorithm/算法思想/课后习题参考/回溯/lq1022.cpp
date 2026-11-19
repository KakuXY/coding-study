/**
 * 2020 国赛 C++/Java/Python A组 (5/10)
 * 玩具蛇
 * https://www.lanqiao.cn/problems/1022/learning/
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  vector<pair<int, int>> dir = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
  };
  auto visited = vector(4, vector(4, 0));
  int ans = 0;
  auto traceback = [&](auto &self, int x, int y, int cnt) {
    if (cnt == 16) {
      ans++;
      return;
    }
    for (auto [dx, dy] : dir) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
      if (visited[nx][ny]) continue;
      visited[nx][ny] = 1;
      self(self, nx, ny, cnt + 1);
      visited[nx][ny] = 0;
    }
  };
  for (int i = 0; i < 4; i ++) {
    for (int j = 0; j < 4; j ++) {
      visited[i][j] = 1;
      traceback(traceback, i, j, 1);
      visited[i][j] = 0;
    }
  }
  cout << ans << endl;
}