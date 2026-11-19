/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30204
 *
 * [3] 无重复字符的最长子串
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
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int hash[128];
    bool hasSame = false;
    increaseEnumerate(0, s.size() - 1,
      [&](int l, int r) {
        return hasSame;
      },
      [&](int l, int r) {
        hash[s[r]]++;
        if (hash[s[r]] == 2) hasSame = true;
      },
      [&](int l, int r) {
        hash[s[l]]--;
        if (hash[s[l]] == 1) hasSame = false;
      },
      [&](int l, int r) {
        ans = max(ans, r - l + 1);
      });
    return ans;
  }
};


// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

