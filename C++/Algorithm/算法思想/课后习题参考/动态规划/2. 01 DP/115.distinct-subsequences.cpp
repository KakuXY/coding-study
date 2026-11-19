/*
 * @lc app=leetcode.cn id=115 lang=cpp
 * @lcpr version=30204
 *
 * [115] 不同的子序列
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int numDistinct(string s, string t) {
    int m = t.size();
    vector<uint32_t> dp(m + 1);
    dp[0] = 1;
    for (auto c : s) {
      for (int i = m - 1; i >= 0; i --) {
        if (t[i] == c) {
          dp[i + 1] += dp[i];
        }
      }
    }
    return dp[m];
  }
};
// @lc code=end



/*
// @lcpr case=start
// "rabbbit"\n"rabbit"\n
// @lcpr case=end

// @lcpr case=start
// "babgbag"\n"bag"\n
// @lcpr case=end

 */

