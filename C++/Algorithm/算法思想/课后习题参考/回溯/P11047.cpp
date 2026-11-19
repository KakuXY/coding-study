/**
 * 24 省赛 Java B组 (7/8)
 * LIST 游戏
 * https://www.lanqiao.cn/problems/19727/learning/
 * https://www.luogu.com.cn/problem/P11047  (数据加强版)
 */

#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<set<vector<string>>> patterns = {
    {
      {
        "111",
        "100"
      },
    },
    {
      {
        "1111",
      }
    },
    {
      {
        "111",
        "010",
      }
    },
    {
      {
        "011",
        "110"
      }
    }
  };
  for (auto &pattern : patterns) {
    auto type = *pattern.begin();
    for (int _ = 0; _ < 4; _ ++) {
      int n = type.size(), m = type[0].size();
      auto new_type = vector(m, string(n, '0'));
      for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
          new_type[j][n - i - 1] = type[i][j];
        }
      }
      type = new_type;
      pattern.insert(new_type);
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    auto board = vector(n, vector(n, 0));
    for (auto &row : board) {
      for (auto &x : row) cin >> x;
    }
    auto candidates = vector(4, vector<vector<int>>());
    for (int k = 0; k < 4; k ++) {
      auto &pattern = patterns[k];
      for (auto &type : pattern) {
        int xl = type.size(), yl = type[0].size();
        for (int x = 0; x + xl <= n; x ++) {
          for (int y = 0; y + yl <= n; y ++) {
            if ([&]() {
              for (int i = 0; i < xl; i ++) {
                for (int j = 0; j < yl; j ++) {
                  if (type[i][j] == '1' && board[x+i][y+j] == 0) return false;
                }
              }
              return true;
            }()) {
              vector<int> candidate;
              for (int i = 0; i < xl; i ++) {
                for (int j = 0; j < yl; j ++) {
                  if (type[i][j] == '1') {
                    candidate.push_back((x + i) * n + (y + j));
                  }
                }
              }
              candidates[k].push_back(candidate);
            }
          }
        }
      }
    }
    vector<int> order{0, 1, 2, 3};
    sort(order.begin(), order.end(), [&](int a, int b) {
      return candidates[a].size() < candidates[b].size();
    });
    vector<int> used(n * n);
    auto can = [&](const vector<int>&candidate) {
      for (auto &pos: candidate) {
        if (used[pos]) return false;
      }
      return true;
    };
    auto update = [&](const vector<int>&candidate) {
      for (auto &pos: candidate) used[pos] = 1;
    };
    auto rollback = [&](const vector<int>&candidate) {
      for (auto &pos: candidate) used[pos] = 0;
    };
    auto traceback = [&](auto &self, int step) -> bool {
      if (step == 4) return true;
      for (auto &candidate : candidates[ order[step] ]) {
        if (can(candidate)) {
          update(candidate);
          if (self(self, step + 1)) return true;
          rollback(candidate);
        }
      }
      return false;
    };
    cout << (traceback(traceback, 0) ? "Yes" : "No") << endl;
  }
}