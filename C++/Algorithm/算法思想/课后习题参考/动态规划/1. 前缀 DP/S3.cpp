#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  while (cin >> n) {
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i ++) cin >> arr[i];
    int nn = n / 2;
    using elem = pair<int, int>;
    const elem inf = {INT_MAX, INT_MAX};
    vector<vector<vector<elem>>> dp(2, vector<vector<elem>>(nn + 1, vector<elem>(2, inf)));
    // dp[i][j][{0, 1}] = {A', B'}
    // 前 i 个数字，j 个在第一个子序列
    // 0: 在众多状态 (i,j,A',B') 中，记录 A' 最小的状态
    // 1: 在众多状态 (i,j,A',B') 中，记录 B' 最小的状态
    
    // dp[i][j][{0, 1}]
    // -> (j, A') (i-j, B')
    dp[0][0][0] = {-1, -1};
    for (int i = 1; i <= n; i ++) {
      auto &cur = dp[i & 1], &pre = dp[~i & 1];
      for (int c = 0; c <= min(nn, i - 1); c ++) {
        cur[c][0] = cur[c][1] = inf;
        auto update = [&](const elem& cand) {
          if (cand < cur[c][0]) cur[c][0] = cand;
          if (elem{cand.second, cand.first} < elem{cur[c][1].second, cur[c][1].first}) {
            cur[c][1] = cand;
          }
        };
        for (int f = 0; f < 2; f ++) {
          if (arr[i] > pre[c][f].second) update({pre[c][f].first, arr[i]});
          if (c && arr[i] > pre[c - 1][f].first) update({arr[i], pre[c - 1][f].second});
        }
      }
    }
    if (dp[n & 1][nn][0] == inf || dp[n & 1][nn][1] == inf) cout << "No!\n";
    else cout << "Yes!\n";
  }
}