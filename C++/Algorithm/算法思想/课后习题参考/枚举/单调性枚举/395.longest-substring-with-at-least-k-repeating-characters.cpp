/*
 * @lc app=leetcode.cn id=395 lang=cpp
 * @lcpr version=30204
 *
 * [395] 至少有 K 个重复字符的最长子串
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
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
    while (r <= e && !match(l, r - 1)) insert(l, r++);
    if (match(l, r - 1)) update(l, r - 2);
    else update(l, r - 1);
    remove(l++, r);
  }
}
class Solution {
public:
  int longestSubstring(string s, int k) {
    // [l, r] <每一个> 字符，出现次数 >= k
    // [l, r] x 个字符  (出现次数 >= k)
    // 条件: 出现的字符种类 > x
    // [l, r] 出现字符 <= x 个的最大区间，(出现次数 >= k)
    // for x : [1:26]
    // O(n * C) C = 26
    int ans = 0;
    for (int x = 1; x <= 26; x++) {
      int cnt[128] = {};
      int typeCnt = 0;
      int matchCnt = 0;
      // for (int l = 0, r = 0; l < s.size();) {
      //   while (r < s.size() && typeCnt <= x) {
      //     char c = s[r++];
      //     if (cnt[c]++ == 0) typeCnt++;
      //     if (cnt[c] == k) matchCnt++;
      //   }
      //   if (matchCnt == x) {
      //     if (typeCnt > x) {
      //       // [l, r - 1] 满足
      //       // [l, r - 2] 不满足
      //       ans = max(ans, r - l - 1);
      //     } else {
      //       // [l, r - 1] 不满足
      //       ans = max(ans, r - l);
      //     }
      //   }
      //   char c = s[l++];
      //   if (cnt[c]-- == k) matchCnt--;
      //   if (cnt[c] == 0) typeCnt--;
      // }
      increaseEnumerate(0, s.size() - 1,
        [&](int l, int r) {
          return typeCnt > x;
        },
        [&](int l, int r) {
          char c = s[r];
          if (cnt[c]++ == 0) typeCnt++;
          if (cnt[c] == k) matchCnt++;
        },
        [&](int l, int r) {
          char c = s[l];
          if (cnt[c]-- == k) matchCnt--;
          if (cnt[c] == 0) typeCnt--;
        },
        [&](int l, int r) {
          // [l, r] 不满足条件
          if (matchCnt == x) {
            ans = max(ans, r - l + 1);
          }
        });
    }
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// "aaabb"\n3\n
// @lcpr case=end

// @lcpr case=start
// "ababbc"\n2\n
// @lcpr case=end

 */

