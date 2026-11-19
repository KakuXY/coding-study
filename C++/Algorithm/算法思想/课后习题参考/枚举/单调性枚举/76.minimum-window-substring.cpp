/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30204
 *
 * [76] 最小覆盖子串
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
  string minWindow(string s, string t) {
    int cntt[128] = {};
    int cnt = 0;
    for (auto c : t) {
      if (cntt[c]++ == 0) cnt++;
    }
    int ansl = -1, sz = s.size() + 1;
    increaseEnumerate(0, s.size() - 1,
          [&](int l, int r) {
            return cnt == 0;
          },
          [&](int l, int r) {
            cntt[ s[r] ]--;
            if (cntt[ s[r] ] == 0) cnt --;
          },
          [&](int l, int r) {
            if (cntt[ s[l] ] == 0) cnt ++;
            cntt[ s[l] ]++;
          },
          [&](int l, int r) {
            if (r + 1 == s.size()) return;
            if (r - l + 2 < sz) {
              sz = r - l + 2;
              ansl = l;
            }
          });
    if (ansl == -1) return "";
    return s.substr(ansl, sz);
  }
};
// @lc code=end



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

