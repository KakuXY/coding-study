/**
 * 23 省赛 C++ B (6/10)
 * 岛屿个数
 * https://www.lanqiao.cn/problems/3513/learning
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dirs = {
  {-1, 0}, {1, 0}, {0, -1}, {0, 1},
  {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    auto maze = vector(n + 2, vector(n + 2, '0'));
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= n; j ++) {
        cin >> maze[i][j];
      }
    }
    auto find_beach = [&](auto &self, int x, int y) {
      if (x < 0 || x > n + 1 || y < 0 || y > n + 1) return;
      if (maze[x][y] == '1') maze[x][y] = '2'; // beach
      if (maze[x][y] != '0') return;
      maze[x][y] = '3'; // visited sea
      for (auto [dx, dy] : dirs) {
        self(self, x + dx, y + dy);
      }
    };
    find_beach(find_beach, 0, 0);
    debug(maze);

    auto fill_land = [&](auto &self, int x, int y) {
      if (maze[x][y] != '2' && maze[x][y] != '1') return;
      maze[x][y] = '4'; // visited land
      for (int i = 0; i < 4; i ++) {
        self(self, x + dirs[i].first, y + dirs[i].second);
      }
    };
    int cnt = 0;
    for (int x = 1; x <= n; x ++) {
      for (int y = 1; y <= n; y ++) {
        if (maze[x][y] == '2') {
          cnt++;
          fill_land(fill_land, x, y);
        }
      }
    }
    cout << cnt << endl;
  }
}