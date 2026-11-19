/*
 * @lc app=leetcode.cn id=354 lang=cpp
 * @lcpr version=30204
 *
 * [354] 俄罗斯套娃信封问题
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& a) {
    sort(a.begin(), a.end(), [&](auto &x, auto &y) {
      if (x[0] == y[0]) return x[1] > y[1];
      return x[0] < y[0];
    });
    vector<int> dp;
    for (auto& x: a) {
      auto iter = lower_bound(dp.begin(), dp.end(), x[1]);
      if (iter == dp.end()) dp.push_back(x[1]);
      else *iter = x[1];
    }
    return dp.size();
  }
};
// @lc code=end



/*
// @lcpr case=start
// [[5,4],[6,4],[6,7],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1],[1,1]]\n
// @lcpr case=end

 */

