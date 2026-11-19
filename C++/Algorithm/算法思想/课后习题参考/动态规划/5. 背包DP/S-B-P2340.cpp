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
  vector<pair<int, int>> goods(n);
  for (auto &[a, b] : goods) cin >> a >> b;
  int offset = 400 * 1000;
  int m = offset * 2 + 1;
  vector<vector<int>> dp(2, vector<int>(m + 1, INT_MIN / 2));
  dp[1][offset] = 0;
  for (int i = 0; i < n; i ++) {
    auto &cur = dp[i & 1], &pre = dp[~i & 1];
    auto [v, w] = goods[i];
    cur = pre;
    for (int j = 0; j <= m; j ++) {
      if (j - v > m || j - v < 0) continue;
      cur[j] = max(cur[j], pre[j - v] + w);
    }
  }
  int ans = 0;
  for (int v = offset; v <= m; v ++) {
    if (dp[~n & 1][v] < 0) continue;
    ans = max(ans, dp[~n & 1][v] + v - offset);
  }
  cout << ans << endl;
}