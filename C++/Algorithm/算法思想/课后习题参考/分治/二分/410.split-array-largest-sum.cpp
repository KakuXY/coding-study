/*
 * @lc app=leetcode.cn id=410 lang=cpp
 * @lcpr version=30204
 *
 * [410] 分割数组的最大值
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start

template <typename T, typename M>
T get_first_match(T lo, T hi, M match) {
  while (lo <= hi) {
    T mid = lo + (hi - lo) / 2;
    if (match(mid)) hi = mid - 1;
    else lo = mid + 1;
  }
  return lo;
}
class Solution {
public:
  int splitArray(vector<int>& nums, int k) {
    int max_e = *max_element(nums.begin(), nums.end());
    return get_first_match(max_e, INT_MAX, [&](int x) {
      int cnt = 1, sum = 0;
      for (auto num: nums) {
        if (sum + num > x) {
          cnt ++;
          sum = num;
          if (cnt > k) return false;
        } else {
          sum += num;
        }
      }
      return true;
    });
  }
};
// @lc code=end



/*
// @lcpr case=start
// [7,2,5,10,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,4]\n3\n
// @lcpr case=end

 */

