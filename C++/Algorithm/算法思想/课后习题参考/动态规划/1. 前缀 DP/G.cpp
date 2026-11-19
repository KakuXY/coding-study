#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

const int mod = 1e9 + 7;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<i64> dp(n + 1, 0);
  dp[0] = 1;
  i64 sum = 0;
  for (int i = 1; i <= n; i ++) {
    if (i >= 3) {
      sum = (sum + dp[i - 3]) % mod;
    }
    if (i == 1) dp[i] = dp[i - 1];
    else dp[i] = (dp[i - 1] + dp[i - 2] + sum * 2) % mod;
  }
  cout << dp[n] << endl;
}