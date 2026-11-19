/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] 全排列
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    // 1 2 3
    // 1 3 2
    // 2 1 3
    // 2 3 1
    // 3 1 2
    // 3 2 1
    do {
      ans.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return ans;
    // int n = nums.size();
    // vector<vector<int>> ans;
    // vector<int> perm;
    // vector<int> used(n);
    // auto traceback = [&](auto &self) {
    //   if (perm.size() == n) {
    //     ans.push_back(perm);
    //     return;
    //   }
    //   for (int i = 0; i < n; i ++) {
    //     if (used[i]) continue;
    //     perm.push_back(nums[i]);
    //     used[i] = true;
    //     self(self);
    //     used[i] = false;
    //     perm.pop_back();
    //   }
    // };
    // traceback(traceback);
    // return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

