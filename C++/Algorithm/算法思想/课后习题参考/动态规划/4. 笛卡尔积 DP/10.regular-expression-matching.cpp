/*
 * @lc app=leetcode.cn id=10 lang=cpp
 * @lcpr version=30204
 *
 * [10] 正则表达式匹配
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    s = " " + s + " ";
    p = " " + p + "  ";
    vector<vector<int>> dp(n + 2, vector<int>(m + 3));
    dp[0][0] = true;
    for (int i = 0; i <= n; i ++) {
      for (int j = 0; j <= m; j ++) {
        auto match = [](char a, char b) {
          return a == b || b == '.';
        };
        if (match(s[i + 1], p[j + 1])) {
          dp[i + 1][j + 1] |= dp[i][j];
        }
        if (p[j + 2] == '*') {
          dp[i][j + 2] |= dp[i][j];
          if (match(s[i + 1], p[j + 1])) {
            dp[i + 1][j] |= dp[i][j];
          }
        }
      }
    }
    return dp[n][m];
  }
};
// @lc code=end



/*
// @lcpr case=start
// "aa"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"a*"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n".*"\n
// @lcpr case=end

 */

