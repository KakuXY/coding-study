/**
 * 23 国赛 C++ B (7/10)
 * AB 路线
 * https://www.lanqiao.cn/problems/17109/learning
 * https://www.luogu.com.cn/problem/P9425
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
  int n, m, K;
  cin >> n >> m >> K;
  vector<string> maze(n);
  for (auto &line : maze) cin >> line;
  auto min_dist = vector(n, vector(m, vector(K, INT_MAX)));
  queue<tuple<int, int, int>> q;
q.emplace(0, 0, 0);
  min_dist[0][0][0] = 0;
  while (!q.empty()) {
    auto [x, y, k] = q.front();
    int step = min_dist[x][y][k];
    q.pop();
    if (x == n - 1 && y == m - 1) {
      cout << step << endl;
      return 0;
    }
    int next_c = maze[x][y];
    if (k == K - 1) next_c = (next_c == 'A') ? 'B' : 'A';
    for (auto [dx, dy] : dirs) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (maze[nx][ny] != next_c) continue;
      int next_k = (k + 1) % K;
      if (min_dist[nx][ny][next_k] <= step + 1) continue;
      min_dist[nx][ny][next_k] = step + 1;
      q.emplace(nx, ny, next_k);
    }
  }
  cout << -1 << endl;
}