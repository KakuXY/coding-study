/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> phone = {
      "",
      "",
      "abc",
      "def",
      "ghi",
      "jkl",
      "mno",
      "pqrs",
      "tuv",
      "wxyz"
    };
    vector<string> ans;
    string comb;
    auto traceback = [&](auto &self) {
      if (comb.size() == digits.size()) {
        if (comb.size() != 0) ans.push_back(comb);
        return;
      }
      int d = digits[ comb.size() ] - '0';
      for (char c: phone[d]) {
        comb += c;
        self(self);
        comb.pop_back();
      }
    };
    traceback(traceback);
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

