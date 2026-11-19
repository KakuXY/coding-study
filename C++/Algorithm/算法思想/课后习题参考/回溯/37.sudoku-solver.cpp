/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=30204
 *
 * [37] 解数独
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  void solveSudoku(vector<vector<char>>& board) {
    int rows[9][9] = {};
    int cols[9][9] = {};
    int grids[3][3][9] = {};
    for (int i = 0; i < 9; i ++) {
      for (int j = 0; j < 9; j ++) {
        if (board[i][j] == '.') continue;
        int d = board[i][j] - '1';
        rows[i][d] = 1;
        cols[j][d] = 1;
        grids[i/3][j/3][d] = 1;
      }
    }
    auto traceback = [&](auto &self, int pos) {
      if (pos == 81) return true;
      int x = pos / 9, y = pos % 9;
      if (board[x][y] != '.') return self(self, pos + 1);
      for (int d = 0; d < 9; d ++) {
        if (rows[x][d] || cols[y][d] || grids[x/3][y/3][d]) continue;
        board[x][y] = d + '1';
        rows[x][d] = 1;
        cols[y][d] = 1;
        grids[x/3][y/3][d] = 1;
        if (self(self, pos + 1)) return true;
        board[x][y] = '.';
        rows[x][d] = 0;
        cols[y][d] = 0;
        grids[x/3][y/3][d] = 0;
      } 
      return false;
    };
    traceback(traceback, 0);
  }
};
// @lc code=end



/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */

