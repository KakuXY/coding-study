#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

constexpr int mod = 1e9 + 7;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> dp(n + 1);
  dp[n] = 1;
  int ans = 0;
  for (int i = n; i > c; i --) {
    if (i - a >= 0) {
      dp[i - a] = (dp[i - a] + dp[i]) % mod;
    } else {
      ans = (ans + dp[i]) % mod;
    }
    if (i - b >= 0) {
      dp[i - b] = (dp[i - b] + dp[i]) % mod;
    } else {
      ans = (ans + dp[i]) % mod;
    }
  }
  for (int i = 0; i <= c; i ++) {
    ans = (ans + dp[i]) % mod;
  }
  cout << ans << endl;
}