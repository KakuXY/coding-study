/**
 * 23 国赛 Java B组 (10/10)
 * 数和游戏
 * https://www.lanqiao.cn/problems/17140/learning/
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  auto board = vector(n, vector<int>(m, -1));
  auto sums = vector(n, vector<pair<int, int>>(m));
  int itemSize = 0;
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      int type;
      cin >> type;
      if (type == 2) {
        cin >> sums[i][j].first >> sums[i][j].second;
        if (sums[i][j].first != -1) itemSize++;
        if (sums[i][j].second != -1) itemSize++;
      } else {
        board[i][j] = 0;
      }
    }
  }
  // sum, cnt, used[]
  // struct Item {
  //   int sum;
  //   int cnt;
  //   vector<int> used;
  // };
  using itemInfo = tuple<int, int, vector<int>>;
  vector<itemInfo> items;
  using itemIds = vector<int>;
  auto pos2item = vector(n, vector(m, itemIds()));
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      if (sums[i][j].first > 0) {
        int cnt = 0;
        for (int k = i + 1; k < n && board[k][j] == 0; k ++) {
          pos2item[k][j].push_back(items.size());
          cnt++;
        }
        items.emplace_back(sums[i][j].first, cnt, vector<int>(10, 0));
      }
      if (sums[i][j].second > 0) {
        int cnt = 0;
        for (int k = j + 1; k < m && board[i][k] == 0; k ++) {
          pos2item[i][k].push_back(items.size());
          cnt++;
        }
        items.emplace_back(sums[i][j].second, cnt, vector<int>(10, 0));
      }
    }
  }
  debug(pos2item);
  debug(items);
  auto can = [&](int x, int y, int d) {
    for (auto itemId: pos2item[x][y]) {
      auto &[sum, cnt, used] = items[itemId];
      if (sum < d) return false;
      if (used[d]) return false;
      if (cnt == 1 && sum != d) return false;
      // 2 sum 20
      // [8, 9]  7+6=13
    }
    return true;
  };
  auto update = [&](int x, int y, int d) {
    board[x][y] = d;
    for (auto itemId: pos2item[x][y]) {
      auto &[sum, cnt, used] = items[itemId];
      sum -= d;
      cnt--;
      used[d] = 1;
    }
  };
  auto rollback = [&](int x, int y, int d) {
    board[x][y] = d;
    for (auto itemId: pos2item[x][y]) {
      auto &[sum, cnt, used] = items[itemId];
      sum += d;
      cnt++;
      used[d] = 0;
    }
  };
  auto traceback = [&](auto &self, int pos) {
    if (pos == n * m) return true;
    int x = pos / m, y = pos % m;
    if (board[x][y] == -1) return self(self, pos + 1);
    for (int d = 1; d <= 9; d ++) {
      if (can(x, y, d)) {
        update(x, y, d);
        if (self(self, pos + 1)) return true;
        rollback(x, y, d);
      }
    }
    return false;
  };
  traceback(traceback, 0);
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      if (board[i][j] == -1) cout << "_ ";
      else cout << board[i][j] << ' ';
    }
    cout << endl;
  }
}