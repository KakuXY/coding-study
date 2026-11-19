/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30204
 *
 * [47] 全排列 II
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    do {
      ans.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return ans;

    
    vector<int> perm;
    vector<int> used(nums.size());
    auto traceback = [&](auto &self) {
      if (perm.size() == nums.size()) {
        ans.push_back(perm);
        return;
      }
      int last = 100;
      for (int i = 0; i < nums.size(); i ++) {
        if (used[i]) continue;
        // [1]
        // [1, 1, 2]
        // [F, T, F]
        if (nums[i] == last) continue;
        last = nums[i];

        used[i] = true;
        perm.push_back(nums[i]);
        self(self);
        perm.pop_back();
        used[i] = false;
      }
    };
    traceback(traceback);
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

