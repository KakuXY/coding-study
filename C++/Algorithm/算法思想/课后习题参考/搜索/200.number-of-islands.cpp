/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30204
 *
 * [200] 岛屿数量
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int cnt = 0;
    auto dfs = [&](auto &self, int x, int y) {
      if (x < 0 || x >= n || y < 0 || y >= m) return;
      if (grid[x][y] != '1') return;
      grid[x][y] = '#';
      self(self, x - 1, y);
      self(self, x + 1, y);
      self(self, x, y - 1);
      self(self, x, y + 1);
    };
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < m; j ++) {
        if (grid[i][j] == '1') {
          cnt++;
          dfs(dfs, i, j);
        }
      }
    }
    return cnt;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end

 */

