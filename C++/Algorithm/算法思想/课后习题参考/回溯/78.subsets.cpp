/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30204
 *
 * [78] 子集
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> subset;
    auto traceback = [&](auto &self, int pos) {
      if (pos == nums.size()) {
        ans.push_back(subset);
        return ;
      }
      self(self, pos + 1);
      subset.push_back(nums[pos]);
      self(self, pos + 1);
      subset.pop_back();
    };
    traceback(traceback, 0);
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

