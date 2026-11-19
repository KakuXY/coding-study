/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30204
 *
 * [93] 复原 IP 地址
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    vector<int> ip;
    auto traceback = [&](auto &self, int pos) {
      if (pos == s.size()) {
        if (ip.size() == 4) {
          ans.push_back(format("{}.{}.{}.{}", ip[0], ip[1], ip[2], ip[3]));
        }
        return;
      }
      // 单独成一组
      if (ip.size() < 4) {
        ip.push_back(s[pos] - '0');
        self(self, pos + 1);
        ip.pop_back();
      }
      // 和前一个数字成一组
      if (ip.size() && ip.back() != 0) {
        int next = ip.back() * 10 + s[pos] - '0';
        if (next <= 255) {
          ip.back() = next;
          self(self, pos + 1);
          ip.back() /= 10;
        }
      }
    };
    traceback(traceback, 0);
    return ans;
  }
};
// @lc code=end



/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */

