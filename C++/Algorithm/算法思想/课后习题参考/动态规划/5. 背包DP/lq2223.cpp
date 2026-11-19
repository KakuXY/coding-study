/**
 * 22 国赛 Java B组 (7/10)
 * 背包与魔法
 * https://www.lanqiao.cn/problems/2223/learning
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<array<int, 2>> dp(m + 1, {0, 0});
  for (int i = 0; i < n; i ++) {
    int w, v;
    cin >> w >> v;
    for (int j = m; j >= w; j --) {
      dp[j][0] = max(dp[j][0], dp[j - w][0] + v);
      dp[j][1] = max(dp[j][1], dp[j - w][1] + v);
      if (j >= w + k) {
        dp[j][1] = max(dp[j][1], dp[j - w - k][0] + v * 2);
      }
    }
  }
  cout << dp[m][1] << endl;
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}