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
  dp[n] = 1;
  int sum = 0;
  for (int d = n - 1; d >= 1; d --) {
    // dp[d];  [d * 2, n]
    if (d * 2 <= n) sum += dp[d * 2];
    if (d * 2 + 1 <= n) sum += dp[d * 2 + 1];
    dp[d] = sum;
  }
  cout << accumulate(dp.begin(), dp.end(), 0);
}