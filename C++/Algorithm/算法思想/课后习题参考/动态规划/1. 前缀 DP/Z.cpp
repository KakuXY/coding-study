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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }
  vector<int> suf_sum(n + 2); // 后缀和
  for (int i = n; i >= 1; i --) {
    suf_sum[i] = suf_sum[i + 1] + a[i];
  }
  vector<int> suf_max_sum(n + 2); // 从 i 开始的最大后缀和 
  for (int i = n; i >= 1; i --) {
    suf_max_sum[i] = max(suf_max_sum[i + 1], suf_sum[i]);
  }

  const int inf = INT_MIN + 1e4;
  int ans = INT_MIN;
  {
    // xx[oooo]xxxx[oooo]xxx
    vector<array<int, 2>> dp(n + 1, {inf, inf});
    // f(i, 0): 第一段以 i 结尾的最大值
    // f(i, 1): 第二段以 i 结尾的最大值
    dp[0][0] = 0;
    int pre_max = inf;
    for (int i = 1; i <= n; i ++) {
      dp[i][0] = max(dp[i - 1][0] + a[i], a[i]);
      if (i > 1) {
        pre_max = max(pre_max, dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][1] + a[i], pre_max + a[i]);
      }
    }
    for (int i = 1; i <= n; i ++) ans = max(ans, dp[i][1]);
  }
  {
    // [oooo]xxx[oooo]xxx[ooo]
    vector<array<int, 2>> dp(n + 1, {inf, inf});
    dp[0][0] = 0;
    int pre_max = inf;
    for (int i = 1; i <= n; i ++) {
      dp[i][0] = dp[i - 1][0] + a[i]; // 没有决策，必须从 1 开始
      if (i > 1) {
        pre_max = max(pre_max, dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][1] + a[i], pre_max + a[i]);
      }
    }
    for (int i = 1; i <= n; i ++) {
      // 从 i + 1 位置及往后，找一个最大后缀
      ans = max(ans, dp[i][1] + max(0, suf_max_sum[i + 1]));
    }
  }
  cout << ans << endl;
}