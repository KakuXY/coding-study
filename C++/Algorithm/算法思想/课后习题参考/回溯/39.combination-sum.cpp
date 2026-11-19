/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> comb;
    auto traceback = [&](auto &self, int lower, int sum) {
      if (sum == target) {
        ans.push_back(comb);
        return;
      }
      for (int i = lower; i < candidates.size(); i ++) {
        if (sum + candidates[i] > target) continue;
        comb.push_back(candidates[i]);
        self(self, i, sum + candidates[i]);
        comb.pop_back();
      }
    };
    traceback(traceback, 0, 0);
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

