#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

// 三维 DP 很好想，f(step, h, w) = {True, False} 第 i 步是否可以到达状态 h, w
// 但复杂度太大，并且状态只表示 TF 非常浪费
// 对于 step 和 h 相同的情况，我们可以想见 w 最大越好（打同样的怪物，血量相同的情况下，魔法值自然是越大越好的）
// 所以状态优化为 f(step, w) = h
// 转移就非常简单，用顺推:
// f(step, w) -> f(step + 1, w - a) // 耗血
// f(step, w) - b -> f(step + 1, w) // 耗蓝
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, h, w;
  cin >> n >> h >> w;
  
  queue<pair<int, int>> q;
  vector<vector<int>> dp(2, vector<int>(h + 1, -1));
  dp[0][h] = w;
  for (int step = 0; step < n; step ++) {
    int x, y;
    cin >> x >> y;
    auto &cur = dp[step & 1], &nxt = dp[~step & 1];
    fill(nxt.begin(), nxt.end(), -1);
    for (int i = 0; i <= h; i ++) {
      if (cur[i] == -1) continue;
      if (i >= x) nxt[i - x] = max(nxt[i - x], cur[i]);
      if (cur[i] >= y) nxt[i] = max(nxt[i], cur[i] - y);
    }
    if (all_of(nxt.begin(), nxt.end(), [](int x) { return x == -1; })) {
      cout << step << '\n';
      return 0;
    }
  }
  cout << n << '\n';
}