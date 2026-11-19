/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 * @lcpr version=30204
 *
 * [1143] 最长公共子序列
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int longestCommonSubsequence(string a, string b) {
    int n = a.size(), m = b.size();
    a = " " + a + " ";
    b = " " + b + " ";
    vector<vector<int>> dp(n + 2, vector<int>(m + 2));
    for (int i = 0; i <= n; i ++) {
      for (int j = 0; j <= m; j ++) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (a[i + 1] == b[j + 1]));
      }
    }
    return dp[n][m];
  }
};
// @lc code=end



/*
// @lcpr case=start
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */

