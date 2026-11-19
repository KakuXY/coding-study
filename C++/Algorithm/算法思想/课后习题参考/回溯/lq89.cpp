/**
 * 16 国赛 C++ A组 (4/6)
 * 路径之谜
 * https://www.lanqiao.cn/problems/2227/learning/
 * https://www.luogu.com.cn/problem/P8642
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dir = {
  {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
int main() {
  int n;
  cin >> n ;
  vector<int> row(n), col(n);
  for (auto &x : col) cin >> x;
  for (auto &x : row) cin >> x;
  auto vis = vector(n, vector(n, 0));
  vector<int> ans;
  auto inside = [&](int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
  };
  int cnt = 0;
  auto traceback = [&](auto &self, int x, int y) {
    cnt++;
    if (x == n - 1 && y == n - 1) {
      if (accumulate(row.begin(), row.end(), 0) == 0 &&
      accumulate(row.begin(), row.end(), 0) == 0) return true;
      return false;
    }
    for (auto &[dx, dy] : dir) {
      int nx = x + dx, ny = y + dy;
      if (!inside(nx, ny)) continue;
      if (vis[nx][ny]) continue;
      if (row[nx] == 0 || col[ny] == 0) continue;
      // if (row[nx] == 1 && accumulate(row.begin(), row.begin() + nx, 0) != 0) continue;
      // if (col[ny] == 1 && accumulate(col.begin(), col.begin() + ny, 0) != 0) continue; 
      vis[nx][ny] = 1;
      row[nx]--;
      col[ny]--;
      ans.push_back(nx * n + ny);
      if (self(self, nx, ny)) return true;
      vis[nx][ny] = 0;
      row[nx]++;
      col[ny]++;
      ans.pop_back();
    }
    return false;
  };
  ans.push_back(0);
  row[0] --;
  col[0] --;
  vis[0][0] = 1;
  traceback(traceback, 0, 0);
  cout << cnt << endl;
  for (auto &pos : ans) cout << pos << ' ';
}