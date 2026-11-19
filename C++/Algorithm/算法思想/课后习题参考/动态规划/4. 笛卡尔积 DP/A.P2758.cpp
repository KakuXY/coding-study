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
  s = " " + s + " ";
  t = " " + t + " ";
  vector<vector<int>> dp(n + 2, vector<int>(m + 2, INT_MAX));
  dp[0][0] = 0;      
  auto checkmin = [](auto &a, auto b) {
    if (b < a) a = b;
  };
  for (int i = 0; i <= n; i ++) {
    for (int j = 0; j <= m; j ++) {
      checkmin(dp[i + 1][j], dp[i][j] + 1);
      checkmin(dp[i][j + 1], dp[i][j] + 1);
      checkmin(dp[i + 1][j + 1], dp[i][j] + (s[i + 1] != t[j + 1]));
    }
  }
  cout << dp[n][m] << endl;
}