/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30204
 *
 * [40] 组合总和 II
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> comb;
    auto traceback = [&](auto &self, int lower, int sum) {
      if (sum == target) {
        ans.push_back(comb);
        return;
      }
      int last = 0;
      for (int i = lower; i < candidates.size(); i ++) {
        if (sum + candidates[i] > target) continue;
        if (candidates[i] == last) continue;
        last = candidates[i];
        
        comb.push_back(candidates[i]);
        self(self, i + 1, sum + candidates[i]);
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
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */

