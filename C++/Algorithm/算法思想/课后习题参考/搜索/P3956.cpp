/**
 * NOIP 2017 普及组
 * 棋盘
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
  auto maze = vector(n, vector(n, -1));
  while (m --) {
    int x, y, c;
    cin >> x >> y >> c;
    maze[x-1][y-1] = c;
  }
  auto min_cost = vector(n, vector(n, vector(2, INT_MAX)));
  auto calced = vector(n, vector(n, vector(2, 0)));
  min_cost[0][0][ maze[0][0] ] = 0;
  using State = tuple<int, int, int, int>; // cost, x, y, c
  priority_queue<State, vector<State>, greater<State>> pq;
  pq.emplace(0, 0, 0, maze[0][0]);
  auto try_update = [&](int cost, int x, int y, int c, int &pre) {
    if (pre < cost) return;
    pre = cost;
    pq.emplace(cost, x, y, c);
  };
  while (!pq.empty()) {
    auto [cost, x, y, c] = pq.top();
    pq.pop();
    if (calced[x][y][c]) continue;
    calced[x][y][c] = true;
    debug(pq.top());
    if (x == n - 1 && y == n - 1) {
      cout << cost << endl;
      return 0;
    }
    for (auto [dx, dy] : dirs) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (maze[x][y] == -1 && maze[nx][ny] == -1) continue;
      if (maze[nx][ny] == -1) {
        // cost + 2 (0 , 1)
        for (int nc = 0; nc <= 1; nc ++) {
          try_update(cost + 2 + (nc != c), nx, ny, nc,
                     min_cost[nx][ny][nc]);
        }
      } else {
        // cost + (c != maze[nx][ny])
        try_update(cost + (maze[nx][ny] != c), nx, ny, maze[nx][ny],
                   min_cost[nx][ny][ maze[nx][ny] ]);
      }
    }
  }
  cout << -1 << endl;
}