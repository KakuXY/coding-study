/**
 * 22 国赛 Java B (5/10)
 * 迷宫
 * https://www.lanqiao.cn/problems/2222/learning
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  auto portals = vector(n + 1, vector(n + 1, vector<pair<int, int>>()));
  while (m--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    portals[a][b].emplace_back(c, d);
    portals[c][d].emplace_back(a, b);
  }
  auto min_dist = vector(n + 1, vector(n + 1, INT_MAX));
  min_dist[n][n] = 0;
  queue<pair<int, int>> q;
  q.emplace(n, n);
  auto try_update = [&](int x, int y, int step, int &pre) {
    if (pre <= step) return ;
    pre = step;
    q.emplace(x, y);
  };
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    int step = min_dist[x][y];
    for (auto [dx, dy] : dirs) {
      int nx = x + dx, ny = y + dy;
      if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
      try_update(nx, ny, step + 1, min_dist[nx][ny]);
    }
    for (auto [nx, ny]: portals[x][y]) {
      try_update(nx, ny, step + 1, min_dist[nx][ny]);
    }
  }
  debug(portals);
  debug(min_dist);
  double sum = 0;
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= n; j ++) {
      sum += min_dist[i][j];
    }
  }
  cout << fixed << setprecision(2) << sum / n / n << endl;
}