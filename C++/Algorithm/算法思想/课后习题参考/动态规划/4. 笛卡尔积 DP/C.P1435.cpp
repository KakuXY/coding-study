#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s + " ";
  string t = s;
  reverse(t.begin(), t.end());

  vector<vector<int>> dp(n + 2, vector<int>(n + 2, INT_MAX));
  dp[0][0] = 0;
  for (int i = 0; i <= n; i ++) {
    for (int j = 0; j <= n; j ++) {
      auto checkmin = [](int &a, int b) { a = a < b ? a : b; };
      checkmin(dp[i + 1][j], dp[i][j] + 1);
      checkmin(dp[i][j + 1], dp[i][j] + 1);
      checkmin(dp[i + 1][j + 1], dp[i][j] + (s[i + 1] != t[j + 1]) * 2);
    }
  }
  cout << dp[n][n] / 2 << endl;
}