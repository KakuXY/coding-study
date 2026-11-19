/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=30204
 *
 * [167] 两数之和 II - 输入有序数组
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    for (int l = 0, r = numbers.size() - 1; l < r; ) {
      if (numbers[l] + numbers[r] == target) return {l + 1, r + 1};
      else if (numbers[l] + numbers[r] < target) l++;
      else r--;
    }
    return {};
  }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */

