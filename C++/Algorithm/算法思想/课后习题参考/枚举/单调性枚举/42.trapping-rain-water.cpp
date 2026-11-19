/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30122
 *
 * [42] 接雨水
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int trap(vector<int>& h) {
    // i    min(leftMax, rightMax)
    // (1, n - 2)
    // l, r
    // [0~l] leftMax,  [r, n-1] rightMax
    //    l   [l+ 1, n-1]
    // min(leftMax, rightMax)
    // leftMax < rightMax  => l   (leftMax-h[l]) l++
    // leftMax > rightMax  => r   (rightMax-h[r]) r--
    int ans = 0;
    int n = h.size();
    for (int l = 1, r = n - 2, leftMax = h[0], rightMax = h[n-1]; l <= r;) {
      leftMax = max(leftMax, h[l]);
      rightMax = max(rightMax, h[r]);
      if (leftMax < rightMax) ans += (leftMax - h[l++]);
      else ans += (rightMax - h[r--]);
    }
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */

