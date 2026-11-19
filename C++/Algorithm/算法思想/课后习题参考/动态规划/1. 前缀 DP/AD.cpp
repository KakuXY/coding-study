/** 
 * 和 X 题几乎一样，只是权值变化了
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  i64 k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<array<i64, 3>> dp(n + 1);
  // [11111][kkkkk][11111]
  // f(i, 0) 没放大
  // f(i, 1) 放大中
  // f(i, 2) 放大结束
  dp[0] = {a[0], a[0] * k, LLONG_MIN / 2};
  for (int i = 1; i < n; i ++) {
    dp[i][0] = dp[i - 1][0] + a[i];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i] * k;
    dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
  }
  cout << max(dp[n - 1][1], dp[n - 1][2]) << endl;
}