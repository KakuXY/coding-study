/*
 * @lc app=leetcode.cn id=435 lang=cpp
 * @lcpr version=30204
 *
 * [435] 无重叠区间
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
      return a[1] < b[1];
    });
    int count = 0;
    int right = -1e5;
    for (auto& interval : intervals) {
      if (interval[0] >= right) {
        right = interval[1];
        count++;
      }
    }
    return intervals.size() - count;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,3],[3,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [1,2], [1,2] ]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [2,3] ]\n
// @lcpr case=end

 */

