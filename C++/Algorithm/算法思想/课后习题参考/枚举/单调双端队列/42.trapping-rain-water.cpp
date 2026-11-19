/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30122
 *
 * [42] 接雨水
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
  int trap(vector<int>& h) {
    auto prev_g = get_next_prev(h, true);
    long long  ans = 0;
    for (int i = 1; i < h.size(); i++) {
      int limit = prev_g[i];
      for (int lowi = i - 1; prev_g[lowi] >= limit; lowi = prev_g[lowi]) {
        int secondLowi = prev_g[lowi];
        if (secondLowi == -1) break;
        int minh = min(h[i], h[secondLowi]);
        ans += (i - secondLowi - 1) * (minh - h[lowi]);
      }
    }
    return ans;
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

