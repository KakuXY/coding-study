/*
 * @lc app=leetcode.cn id=1926 lang=cpp
 * @lcpr version=30204
 *
 * [1926] 迷宫中离入口最近的出口
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  vector<pair<int, int>> dir {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
  };
public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int n = maze.size(), m = maze[0].size();
    int sx = entrance[0], sy = entrance[1];
    auto min_dist = vector(n, vector(m, INT_MAX));
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    min_dist[sx][sy] = 0;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      int step = min_dist[x][y];
      if (x != sx || y != sy) {
        if (x == 0 || y == 0 || x == n - 1 || y == m - 1) return step;
      }
      for (auto [dx, dy] : dir) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (maze[nx][ny] == '+') continue;
        if (min_dist[nx][ny] <= step + 1) continue;
        min_dist[nx][ny] = step + 1;
        q.emplace(nx, ny);
      }
    }
    return -1;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]\n[1,2]\n
// @lcpr case=end

// @lcpr case=start
// [["+","+","+"],[".",".","."],["+","+","+"]]\n[1,0]\n
// @lcpr case=end

// @lcpr case=start
// [[".","+"]]\n[0,0]\n
// @lcpr case=end

 */

