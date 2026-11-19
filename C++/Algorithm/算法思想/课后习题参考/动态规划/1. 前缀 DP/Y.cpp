#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<array<i64, 2>> dp(n + 1, {LLONG_MIN / 2, LLONG_MIN / 2});
  // f(i, 0): 第一段以 i 结尾的最大值
  // f(i, 1): 第二段以 i 结尾的最大值
  dp[0][0] = 0;
  i64 pre_max = LLONG_MIN / 2;
  for (int i = 1; i <= n; i ++) {
    i64 x;
    cin >> x;
    dp[i][0] = max(dp[i - 1][0] + x, x);
    if (i > 2) {
      pre_max = max(pre_max, dp[i - 2][0]); // 从前 i - 2 最大的值转移过来
      dp[i][1] = max(dp[i - 1][1] + x, pre_max + x);
    }
  }
  i64 ans = LLONG_MIN;
  for (int i = 0; i <= n; i ++) {
    ans = max(ans, dp[i][1]);
  }
  cout << ans << endl;
}