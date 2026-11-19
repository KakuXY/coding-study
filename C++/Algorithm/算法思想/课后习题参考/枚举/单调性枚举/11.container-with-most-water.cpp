/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=30204
 *
 * [11] 盛最多水的容器
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int maxArea(vector<int>& height) {
    // min(h[i], h[j]) * dis(i, j)
    // j 递减 dis 递减
    // j 递减 min(h[i], h[j]) 递减（变小）
    // h[i] < h[j]    <=    min(h[i], h[j])
    // (0, 1) (0, 2) (0, 3) (0, 4)
    //                      (1, 4)
    //                      (2, 4)
    //                      (3, 4)

    // h[0] < h[4]
    // min(h[0], h[4]) = h[0] * (4 - 0)
    // h[i] (i < 4)
    // min(h[0], h[i]) * (i - 0)
    int ans = 0;
    for (int l = 0, r = height.size() - 1; l < r;) {
      ans = max(ans, min(height[l], height[r]) * (r - l));
      if (height[l] < height[r]) l++;
      else r--;
    }
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

