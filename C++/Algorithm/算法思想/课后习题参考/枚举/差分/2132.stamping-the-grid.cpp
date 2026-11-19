/*
 * @lc app=leetcode.cn id=2132 lang=cpp
 * @lcpr version=30204
 *
 * [2132] 用邮票贴满网格图
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
    int n = grid.size(), m = grid[0].size();
    auto sum = vector(n + 2, vector(m + 2, 0));
    for (int i = 0; i < n; i ++) {
      partial_sum(grid[i].begin(), grid[i].end(), sum[i + 1].begin() + 1);
      for (int j = 1; j <= m; j ++) {
        sum[i + 1][j] += sum[i][j];
      }
    }
    auto diff = vector(n + 2, vector(m + 2, 0));
    for (int i = 0; i + h <= n; i ++) {
      for (int j = 0; j + w <= m; j ++) {
        // (i + 1, j + 1) -> (i + h, j + w)
        int v = sum[i + h][j + w] -
                sum[i + h][j] -
                sum[i][j + w] +
                sum[i][j];
        if (v == 0) {
          diff[i + 1][j + 1] += 1;
          diff[i + 1][j + w + 1] -= 1;
          diff[i + h + 1][j + 1] -= 1;
          diff[i + h + 1][j + w + 1] += 1;
        }
      }
    }
    for (int i = 0; i < diff.size(); i ++) {
      partial_sum(diff[i].begin(), diff[i].end(), diff[i].begin());
      for (int j = 0; j < diff[i].size(); j ++) {
        if (i) diff[i][j] += diff[i - 1][j];
      }
    }
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= m; j ++) {
        if (grid[i - 1][j - 1] == 0 && diff[i][j] == 0) return false;
      }
    }
    return true;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]\n2\n2\n
// @lcpr case=end

 */

