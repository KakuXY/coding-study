/**
 * 23 国赛 C++ A组 (7/10)
 * 01 游戏
 * https://www.lanqiao.cn/problems/17100/learning/
 * https://www.luogu.com.cn/problem/P10419
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dir = {
  {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<string> board(n);
  for (auto &line : board) cin >> line;
  auto inside = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
  };
  auto check = [&]() {
    set<int> rows, cols;
    for (int i = 0; i < n; i ++) {
      int row = 0;
      for (int j = 0; j < n; j ++) {
        if (board[i][j] == '1') row |= (1 << j);
      }
      if (rows.find(row) != rows.end()) return false;
      rows.insert(row);
    }
    for (int j = 0; j < n; j ++) {
      int col = 0;
      for (int i = 0; i < n; i ++) {
        if (board[i][j] == '1') col |= (1 << i);
      }
      if (cols.find(col) != cols.end()) return false;
      cols.insert(col);
    }
    return true;
  };
  auto can = [&](int x, int y, char c) {
    for (auto [dx, dy] : dir) {
      int nx = x + dx, ny = y + dy;
      int cnt = 0;
      while (inside(nx, ny) && board[nx][ny] == c) {
        cnt++;
        if (cnt == 2) return false;
        nx = nx + dx;
        ny = ny + dy;
      }
    }
    if (x == n - 1) {
      int cntZero = c == '0';
      for (int i = 0; i < n - 1; i ++) {
        if (board[i][y] == '0') cntZero ++;
      }
      if (cntZero * 2 != n) return false;
    }
    if (y == n - 1) {
      int cntZero = c == '0';
      for (int i = 0; i < n - 1; i ++) {
        if (board[x][i] == '0') cntZero ++;
      }
      if (cntZero * 2 != n) return false;
    }
    return true;
  };
  auto traceback = [&](auto &self, int pos) {
    if (pos == n * n) return check();
    int x = pos / n, y = pos % n;
    if (board[x][y] != '_') {
      if (!can(x, y, board[x][y])) return false;
      return self(self, pos + 1);
    }
    for (char c = '0'; c <= '1'; c ++) {
      if (can(x, y, c)) {
        board[x][y] = c;
        if (self(self, pos + 1)) return true;
        board[x][y] = '_';
      }
    }
    return false;
  };
  traceback(traceback, 0);
  for (auto &line : board) cout << line << endl;
}