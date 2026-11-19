/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30204
 *
 * [84] 柱状图中最大的矩形
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
template <template<typename> typename Cmp = greater, typename T>
vector<int> get_next_prev(vector<T> &arr, bool prev = false) {
  int n = arr.size();
  vector<int> res(n);
  stack<int> st;
  for (int i = prev ? 0 : n - 1; prev ? i < n : i >= 0; prev ? ++i : --i) {
    while (!st.empty() && !Cmp<T>()(arr[st.top()], arr[i])) st.pop();
    res[i] = st.empty() ? (prev ? -1 : n) : st.top();
    st.push(i);
  }
  return res;
}

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    auto next_l = get_next_prev<less>(heights);
    auto prev_l = get_next_prev<less>(heights, true);
    long long total = 0;
    for (int i = 0; i < heights.size(); i ++) {
      total = max(total, 1ll * heights[i] * (next_l[i] - prev_l[i] - 1));
    }
    return total;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */

