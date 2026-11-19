/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30204
 *
 * [209] 长度最小的子数组
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
  int minSubArrayLen(int target, vector<int>& arr) {
    int n = arr.size();
    int ans = n + 1;
    int sum = 0;
    increaseEnumerate(0, n - 1,
      [&](int l, int r) {
        return sum >= target;
      },
      [&](int l, int r) {
        sum += arr[r];
      },
      [&](int l, int r) {
        sum -= arr[l];
      },
      [&](int l, int r) {
        if (r + 1 == n) return;
        ans = min(ans, r - l + 2);
      });
    return ans == arr.size() + 1 ? 0 : ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

