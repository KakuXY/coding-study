/**
 * 18 国赛 C++ C (6/6)
 * 迷宫与陷阱
 * https://www.lanqiao.cn/problems/229/learning
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
  int n, k;
  cin >> n >> k;
  vector<string> maze(n);
  for (auto &line : maze) cin >> line;
  auto min_dist = vector(n, vector(n, vector(k + 1, INT_MAX)));
  queue<tuple<int, int, int>> q;
  min_dist[0][0][0] = 0;
  q.emplace(0, 0, 0);
  while (!q.empty()) {
    auto [x, y, wudi] = q.front();
    int step = min_dist[x][y][wudi];
    q.pop();
    if (x == n - 1 && y == n - 1) {
      cout << step << endl;
      return 0;
    }
    for (auto [dx, dy]: dirs) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (maze[nx][ny] == '#') continue;
      if (maze[nx][ny] == 'X' && wudi == 0) continue;
      int next_wudi = max(0, wudi - 1);
      if (maze[nx][ny] == '%') next_wudi = k;
      if (min_dist[nx][ny][next_wudi] > step + 1) {
        min_dist[nx][ny][next_wudi] = step + 1;
        q.emplace(nx, ny, next_wudi);
      }
    }
  }
  cout << -1 << endl;
}