/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30204
 *
 * [51] N 皇后
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<int> col(n, 0), dg(2 * n, 0), bdg(2 * n, 0);
    auto trackback = [&](auto &self, int row) {
      if (row == n) {
        ans.push_back(board);
        return;
      }
      for (int i = 0; i < n; i ++) {
        if (col[i] || dg[row + i] || bdg[row - i + n]) continue;
        board[row][i] = 'Q';
        col[i] = dg[row + i] = bdg[row - i + n] = 1;
        self(self, row + 1);
        board[row][i] = '.';
        col[i] = dg[row + i] = bdg[row - i + n] = 0;
      }
    };
    trackback(trackback, 0);
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

