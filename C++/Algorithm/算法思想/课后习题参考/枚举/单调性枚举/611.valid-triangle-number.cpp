/*
 * @lc app=leetcode.cn id=611 lang=cpp
 * @lcpr version=30204
 *
 * [611] 有效三角形的个数
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
/**
 * 单调性枚举（区间）模版
 * [s, e] 闭区间
 * match 判断是否满足条件
 * insert 插入右端点
 * remove 删除左端点
 * update 更新答案
 *    [l, r] 是不满足条件的最大区间
 *           如果在 update 时需要使用维护的关键值，因为维护的关键值包含了 r+1，所以需要删除 r+1 进行更新后再加回去
 *    [l, r+1] 是满足条件的最小区间
 *             使用时需要判断 r+1 是否越界
 */
template<typename M, typename I, typename R, typename U>
void increaseEnumerate(int s, int e,
                       const M& match,
                       const I& insert,
                       const R& remove,
                       const U& update) {
  for (int l = s, r = s; l <= e; ) {
    while (l == r || (r <= e && !match(l, r - 1))) insert(l, r++);
    if (match(l, r - 1)) update(l, r - 2);
    else update(l, r - 1);
    remove(l++, r);
  }
}
class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      increaseEnumerate(i + 1, nums.size() - 1,
          [&](int l, int r) {
            return l < r && nums[i] + nums[l] <= nums[r];
          },
          [&](int l, int r) {},
          [&](int l, int r) {},
          [&](int l, int r) {
            ans += r - l;
          });
    }
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,3,4]\n
// @lcpr case=end

 */

