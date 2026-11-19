/**
 * 22 国赛 Python B组 (7/10)
 * 点亮
 * https://www.lanqiao.cn/problems/2227/learning/
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dir = {
  {1, 0}, {0, 1}, {0, -1}, {-1, 0}
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<string> board(n);
  for (auto &line : board) cin >> line;
  auto cnt = vector(n, vector(n, 0));
  auto lighted = vector(n, vector(n, 0));
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      if (isdigit(board[i][j])) {
        cnt[i][j] = board[i][j] - '0';
      }
    }
  }
  auto check = [&]() {
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < n; j ++) {
        if (board[i][j] == '.' && lighted[i][j] == 0) return false;
        if (isdigit(board[i][j]) && cnt[i][j] != 0) return false;
      }
    }
    return true;
  };
  auto inside = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
  };
  auto can = [&](int x, int y, int put) {
    if (put) {
      for (auto [dx, dy] : dir) {
        int nx = x + dx, ny = y + dy;
        if (!inside(nx, ny)) continue;
        if (isdigit(board[nx][ny]) && cnt[nx][ny] == 0) {
          return false;
        }
        while (inside(nx, ny)) {
          if (isdigit(board[nx][ny]) || board[nx][ny] == 'X') break;
          if (board[nx][ny] == 'O') return false;
          nx += dx, ny += dy;
        }
      }
    } else {
      for (int d = 0; d < 4; d ++) {
        int nx = x + dir[d].first, ny = y + dir[d].second;
        if (!inside(nx, ny)) continue;
        if (isdigit(board[nx][ny]) && cnt[nx][ny] >= 4 - d) return false;
      }
    }
    return true;
  };
  auto update = [&](int x, int y) {
    board[x][y] = 'O';
    for (auto [dx, dy] : dir) {
      int nx = x + dx, ny = y + dy;
      if (!inside(nx, ny)) continue;
      if (isdigit(board[nx][ny])) cnt[nx][ny]--;
    }
    lighted[x][y]++;
    for (auto [dx, dy] : dir) {
      int nx = x + dx, ny = y + dy;
      while (inside(nx, ny)) {
        if (isdigit(board[nx][ny]) || board[nx][ny] == 'X') break;
        lighted[nx][ny]++;
        nx += dx, ny += dy;
      }
    }
  };
  auto rollback = [&](int x, int y) {
    board[x][y] = '.';
    for (auto [dx, dy] : dir) {
      int nx = x + dx, ny = y + dy;
      if (!inside(nx, ny)) continue;
      if (isdigit(board[nx][ny])) cnt[nx][ny]++;
    }
    lighted[x][y]--;
    for (auto [dx, dy] : dir) {
      int nx = x + dx, ny = y + dy;
      while (inside(nx, ny)) {
        if (isdigit(board[nx][ny]) || board[nx][ny] == 'X') break;
        lighted[nx][ny]--;
        nx += dx, ny += dy;
      }
    }
  };
  auto traceback = [&](auto &self, int pos) {
    if (pos == n * n) return check();
    int x = pos / n, y = pos % n;
    if (board[x][y] != '.') return self(self, pos + 1);
    
    if (can(x, y, 1)) {
      update(x, y);
      if (self(self, pos + 1)) return true;
      rollback(x, y);
    }
    if (can(x, y, 0)) {
      if (self(self, pos + 1)) return true;
    }
    return false;
  };
  if (traceback(traceback, 0))
    for (auto &line : board) cout << line << endl;
}