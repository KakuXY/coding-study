#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  s = " " + s + "  ";
  t = " " + t + "  ";
  int del, rep, cpy, ins, twi;
  cin >> del >> rep >> cpy >> ins >> twi;
  vector<vector<int>> dp(n + 3, vector<int>(m + 3, INT_MAX));
  dp[0][0] = 0;
  for (int i = 0; i <= n; i ++) {
    for (int j = 0; j <= m; j ++) {
      auto checkmin = [&](int &a, int b) {
        a = a < b ? a : b;
      };
      // delelte
      checkmin(dp[i + 1][j], dp[i][j] + del);
      // ins
      checkmin(dp[i][j + 1], dp[i][j] + ins);
      if (s[i + 1] == t[j + 1]) {
        // copy
        checkmin(dp[i + 1][j + 1], dp[i][j] + cpy);
      }
      // replace
      checkmin(dp[i + 1][j + 1], dp[i][j] + rep);
      // twiddle
      if (s[i + 1] == t[j + 2] && s[i + 2] == t[j + 1]) {
        checkmin(dp[i + 2][j + 2], dp[i][j] + twi);
      }
    }
  }
  int ans = dp[n][m];
  for (int i = 0; i < n; i ++) {
    // kill
    ans = min(ans, dp[i][m] + (n - i) * del - 1);
  }
  cout << ans << endl;
}