/*
 * @lc app=leetcode.cn id=16 lang=cpp
 * @lcpr version=30204
 *
 * [16] 最接近的三数之和
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n; i ++) {
      for (int l = i + 1, r = n - 1; l < r; ) {
        int sum = nums[i] + nums[l] + nums[r];
        if (abs(sum - target) < abs(ans - target)) ans = sum;
        if (sum < target) l++;
        else r--;
      }
    }
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,2,1,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n1\n
// @lcpr case=end

 */

