/*
 * @lc app=leetcode.cn id=679 lang=cpp
 * @lcpr version=30204
 *
 * [679] 24 点游戏
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  bool judgePoint24(vector<int>& cards) {
    string ops = "+-*/";
    vector<double> nums(4);
    for (int i = 0; i < 4; i ++) nums[i] = cards[i];
    vector<int> used(4, 0);
    auto calc = [&](double a, double b, char op) {
      if (op == '+') return a + b;
      if (op == '-') return a - b;
      if (op == '*') return a * b;
      return a / b;
    };
    auto traceback = [&](auto &self, int step) {
      if (step == 3) {
        return abs(nums.back() - 24) < 1e-6;
      }
      for (int i = 0; i < nums.size(); i ++) {
        if (used[i]) continue;
        for (int j = 0; j < nums.size(); j ++) {
          if (used[j] || i == j) continue;
          used[i] = used[j] = 1;
          for (char op : ops) {
            nums.push_back(calc(nums[i], nums[j], op));
            used.push_back(0);
            if (self(self, step + 1)) return true;
            nums.pop_back();
            used.pop_back();
          }
          used[i] = used[j] = 0;
        }
      }
      return false;
    };
    return traceback(traceback, 0);
  }
};
// @lc code=end



/*
// @lcpr case=start
// [4, 1, 8, 7]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 1, 2]\n
// @lcpr case=end

 */

