/*
 * @lc app=leetcode.cn id=44 lang=cpp
 * @lcpr version=30204
 *
 * [44] 通配符匹配
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
    p = " " + p + " ";
    vector<vector<int>> dp(n + 2, vector<int>(m + 2));
    dp[0][0] = true;
    for (int i = 0; i <= n; i ++) {
      for (int j = 0; j <= m; j ++) {
        if (!dp[i][j]) continue;
        if (s[i + 1] == p[j + 1] || p[j + 1] == '?') {
          dp[i + 1][j + 1] = true;
        }
        if (p[j + 1] == '*') {
          dp[i][j + 1] = dp[i + 1][j] = true;
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
// "aa"\n"*"\n
// @lcpr case=end

// @lcpr case=start
// "cb"\n"?a"\n
// @lcpr case=end

 */

