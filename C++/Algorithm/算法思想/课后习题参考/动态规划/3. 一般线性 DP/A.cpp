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
  vector<int> dp(n + 1);
  dp[1] = 0;
  for (int i = 2; i <= n; i ++) {
    if (i & 1) dp[i] = dp[i - 1] + 1;
    else dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
  }
  cout << dp[n] << endl;
}