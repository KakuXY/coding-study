#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dir = {
  {-1, -1}, {-1, 0}, {-1, 1},
  {0, -1}, {0, 0}, {0, 1},
  {1, -1}, {1, 0}, {1, 1}
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> cnt(n, vector<int>(m, -1));
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      char ch;
      cin >> ch;
      if (isdigit(ch)) cnt[i][j] = ch - '0';
    }
  }
  auto inside = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  vector<vector<vector<int>>> limit(n, vector<vector<int>>(m, vector<int>(9)));
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      for (int d = 0; d < 9; d ++) {
        auto [dx, dy] = dir[d];
        int nx = i + dx, ny = j + dy;
        if (!inside(nx, ny)) continue;
        int c = 0;
        for (int dd = 9 - d; dd < 9; dd ++) {
          auto [ddx, ddy] = dir[dd];
          int nnx = nx + ddx, nny = ny + ddy;
          if (inside(nnx, nny)) c++;
        }
        limit[i][j][d] = c;
      }
    }
  }
  debug(limit);
  using tiii = tuple<int, int, int>;
  vector<vector<vector<tiii>>> neb(n, vector<vector<tiii>>(m));
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      for (int d = 0; d < 9; d ++) {
        auto [dx, dy] = dir[d];
        int nx = i + dx, ny = j + dy;
        if (!inside(nx, ny)) continue;
        if (cnt[nx][ny] == -1) continue;
        neb[i][j].emplace_back(nx, ny, limit[i][j][d]);
      }
    }
  }
  vector<string> board(n, string(m, '0'));
  auto can = [&](int x, int y, int c) {
    for (auto [nx, ny, limit] : neb[x][y]) {
      if (c == 0) {
        if (cnt[nx][ny] > limit) return false;
      } else {
        if (cnt[nx][ny] == 0) return false;
      }
    }
    return true;
  };
  auto update = [&](int x, int y) {
    board[x][y] = '1';
    for (auto [nx, ny, _] : neb[x][y]) {
      cnt[nx][ny] --;
    }
  };
  auto rollback = [&](int x, int y) {
    board[x][y] = '0';
    for (auto [nx, ny, _] : neb[x][y]) {
      cnt[nx][ny] ++;
    }
  };
  auto traceback = [&](auto &self, int pos) {
    if (pos == n * m) return true;
    int x = pos / m, y = pos % m;
    if (can(x, y, 0)) {
      if (self(self, pos + 1)) return true;
    }
    if (can(x, y, 1)) {
      update(x, y);
      if (self(self, pos + 1)) return true;
      rollback(x, y);
    }
    return false;
  };
  traceback(traceback, 0);
  for (auto &line : board) cout << line << endl;
}