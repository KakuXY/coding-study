/**
 * 和 X 类似，从 1 段区间扩展到了 m 段区间
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  auto f = [](int n) {
    int res = 0;
    for (; n; n /= 2) {
      res = res * 2 + (n % 2);
    }
    return res;
  };
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<i64>> dp(n, vector<i64>(2 * m + 1, LLONG_MIN / 2));
  dp[0][0] = a[0];
  dp[0][1] = f(a[0]);
  for (int i = 1; i < n; i ++) {
    for (int j = 0; j <= 2 * m; j += 2) {
      if (j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i];
      else dp[i][j] = dp[i - 1][j] + a[i];
    }
    for (int j = 1; j <= 2 * m; j += 2) {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + f(a[i]);
    }
  }
  cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
}