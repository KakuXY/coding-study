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
  int m = n * 5 + 1;
  const int inf = INT_MAX / 2;
  vector<int> dp(m + 1, inf);
  dp[0] = 0;
  for (int t = 1; t <= n; t ++) {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = m ; i >= 0; i --) {
      int temp = inf;
      if (a && i >= a) {
        temp = min(temp, dp[i - a]);
      }
      if (b) {
        temp = min(temp, dp[i] + b);
      }
      if (c && i >= c) {
        temp = min(temp, dp[i - c] + c);
      }
      dp[i] = temp;
    }
  }
  int ans = inf;
  for (int i = 0; i <= m; i ++) {
    ans = min(ans, max(i, dp[i]));
  }
  cout << ans << endl;
}