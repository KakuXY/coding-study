/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30204
 *
 * [42] 接雨水
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start

class Solution {
public:
  int trap(vector<int>& h) {
    int n = h.size();
    vector<int> left_max(n), right_max(n);
    // for (int i = 0; i < n; i ++) {
    //   if (i == 0) left_max[i] = h[i];
    //   else left_max[i] = max(left_max[i - 1], h[i]);
    // }
    // for (int i = n - 1; i >= 0; i --) {
    //   if (i == n - 1) right_max[i] = h[i];
    //   else right_max[i] = max(right_max[i + 1], h[i]);
    // }
    partial_sum(h.begin(), h.end(), left_max.begin(), [&](int prev, int cur) {
      return max(prev, cur);
    });
    partial_sum(h.rbegin(), h.rend(), right_max.rbegin(), [&](int prev, int cur) {
      return max(prev, cur);
    });
    int sum = 0;
    for (int i = 1; i < n - 1; i ++) {
      // sum += max(0, min(left_max[i-1], right_max[i+1]) - h[i]);
      sum += min(left_max[i], right_max[i]) - h[i];
    }
    return sum;
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

