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
    const int inf = INT_MAX;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(nn + 1, vector<int>(2, inf)));
    // dp[i][j][{0, 1}]
    // 前 i 个数字，j 个在第一个子序列
    // 0: arr[i] 在第一个子序列，第二个子序列的值最小
    // 1: arr[i] 在第二个子序列，第一个子序列的值最小
    
    // dp[i][j][0]
    // -> (j, arr[i]) (i-j, dp[i][j][0])
    // dp[i][j][1]
    // -> (j, dp[i][j][1]) (i-j, arr[i])
    dp[0][0][0] = -1;
    arr[0] = -1;
    for (int i = 1; i <= n; i ++) {
      auto &cur = dp[i & 1], &pre = dp[~i & 1];
      for (int c = 0; c <= nn; c ++) {
        cur[c][0] = cur[c][1] = inf;
        // arr[i-1], pre[c-1][0]
        if (c && arr[i] > arr[i - 1]) cur[c][0] = min(cur[c][0], pre[c - 1][0]);
        // pre[c-1][1], arr[i-1]
        if (c && arr[i] > pre[c - 1][1]) cur[c][0] = min(cur[c][0], arr[i - 1]);

        // pre[c][1], arr[i-1]
        if (arr[i] > arr[i - 1]) cur[c][1] = min(cur[c][1], pre[c][1]);
        // arr[i-1], pre[c][0]
        if (arr[i] > pre[c][0]) cur[c][1] = min(cur[c][1], arr[i - 1]);
      }
      debug(cur);
    }
    if (dp[n & 1][nn][0] == inf && dp[n & 1][nn][1] == inf) cout << "No!\n";
    else cout << "Yes!\n";
  }
}