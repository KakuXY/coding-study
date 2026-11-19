#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

constexpr int mod = 1e9 + 7;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, K;
  cin >> n >> m >> K;
  string a, b;
  cin >> a >> b;
  a = " " + a;
  b = " " + b;
  vector<vector<array<uint32_t, 2>>> dp(n + 1, vector<array<uint32_t, 2>>(m + 1));
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i ++) {
    for (int j = m; j >= 1; j --) {
      for (int k = K; k >= 1; k --) {
        // dp[j][k][0], dp[j][k][1]
        // dp[j][k][0] = 0, dp[j][k][1] = 0
        (dp[j][k][0] += dp[j][k][1]) %= mod;
        if (a[i] == b[j]) {
          dp[j][k][1] = (dp[j - 1][k][1] +
                         dp[j - 1][k - 1][0] +
                         dp[j - 1][k - 1][1]) % mod;
        } else {
          dp[j][k][1] = 0;
        }
      }
    }
  }
  cout << (dp[m][K][0] + dp[m][K][1]) % mod << endl;
}