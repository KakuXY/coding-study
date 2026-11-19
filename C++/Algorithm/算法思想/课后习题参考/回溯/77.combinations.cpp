/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30204
 *
 * [77] 组合
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> combine;
    auto traceback = [&](auto &self) {
      if (combine.size() == k) {
        ans.push_back(combine);
        return;
      }
      int lower = combine.size() == 0 ? 1 : combine.back() + 1;
      for (int i = lower; i <= n; i ++) {
        combine.push_back(i);
        self(self);
        combine.pop_back();
      }
    };
    traceback(traceback);
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

