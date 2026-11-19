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
  vector<vector<int>> dp(n + 2, vector<int>(m + 2));
  dp[0][0] = true;
  for (int i = 0; i <= n; i ++) {
    for (int j = 0; j <= m; j ++) {
      if (s[i + 1] == t[j + 1] || s[i + 1] == '?') {
        dp[i + 1][j + 1] |= dp[i][j];
      }
      if (s[i + 1] == '*') {
        dp[i + 1][j] |= dp[i][j];
        dp[i][j + 1] |= dp[i][j];
      }
    }
  }
  if (!dp[n][m]) {
    cout << "not matched" << endl;
    return 0;
  }
  cout << "matched" << endl;
  if (n == m) {
    cout << 0 << endl;
    return 0;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i ++) {
    cnt += (s[i] != '?' && s[i] != '*');
  }
  int remain = m - cnt;
  int ans = remain;
  for (int k = remain; k >= 2; k --) {
    if (remain % k) continue;
    for (int i = 0; i <= n; i++) {
      fill(dp[i].begin(), dp[i].end(), 0);
    }
    dp[0][0] = true;
    for (int i = 0; i <= n; i ++) {
      for (int j = 0; j <= m; j ++) {
        if (s[i + 1] == t[j + 1]) {
          dp[i + 1][j + 1] |= dp[i][j];
        }
        if (s[i + 1] == '*' || s[i + 1] == '?') {
          dp[i + 1][j] |= dp[i][j];
          if (j + k <= m) dp[i][j + k] |= dp[i][j];
        }
      }
    }
    if (!dp[n][m]) continue;
    ans = remain / k;
    break;
  }
  cout << ans << endl;
}