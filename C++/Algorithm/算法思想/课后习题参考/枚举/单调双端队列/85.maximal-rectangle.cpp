/*
 * @lc app=leetcode.cn id=85 lang=cpp
 * @lcpr version=30204
 *
 * [85] 最大矩形
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
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
  int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    auto heights = vector(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < m; j ++) {
        if (matrix[i][j] == '0') continue;
        heights[i][j] = 1;
        if (i) heights[i][j] += heights[i - 1][j];
      }
    }
    int ans = 0;
    for (int x = 0; x < n; x++) {
      auto prev_l = get_next_prev<less>(heights[x], true);
      auto next_l = get_next_prev<less>(heights[x]);
      for (int i = 0; i < m; i ++) {
        ans = max(ans, (next_l[i] - prev_l[i] - 1) * heights[x][i]);
      }
    }
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1"]]\n
// @lcpr case=end

 */

