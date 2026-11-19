#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, T;
  cin >> n >> m >> T;
  vector<vector<int>> goods(n, vector<int>(m + 1));
  for (int _ = 0; _ < n; _ ++) {
    string str;
    cin >> str;
    vector<int> ones(m + 1);
    for (int i = 1; i <= m; i ++) {
      ones[i] = ones[i - 1] + (str[i - 1] == '1');
    }
    debug(ones);
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    for (int i = 1; i <= m; i ++) {
      for (int j = 1; j <= m; j ++) {
        for (int k = 0; k < j; k ++) {
          int one = ones[j] - ones[k];
          int len = j - k;
          dp[i][j] = max(dp[i][j], dp[i - 1][k] + max(one, len - one));
        }
      }
    }
    for (int i = 1; i <= m; i ++) {
      goods[_][i] = dp[i][m];
    }
  }
  vector<int> dp(T + 1);
  for (int i = 0; i < n; i ++) {
    for (int k = T; k >= 0; k --) {
      for (int j = 0; j <= min(k, m); j ++) {
        dp[k] = max(dp[k], dp[k - j] + goods[i][j]);
      }
    }
  }
  cout << dp[T] << endl;
}