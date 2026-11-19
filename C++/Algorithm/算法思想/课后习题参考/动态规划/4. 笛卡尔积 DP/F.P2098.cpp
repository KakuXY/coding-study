#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

constexpr int mod = 1e9 + 9;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, K;
  cin >> n >> m >> K;
  vector<int> a(n + 2), b(m + 2);
  for (int i = 1; i <= n; i ++) cin >> a[i];
  for (int i = 1; i <= m; i ++) cin >> b[i];
  sort(a.begin() + 1, a.begin() + 1 + n);
  sort(b.begin() + 1, b.begin() + 1 + m);
  vector<vector<array<int, 12>>> dp(n + 2, vector<array<int, 12>>(m + 2));
  dp[0][0][0] = 1;
  for (int i = 0; i <= n; i ++) {
    for (int j = 0; j <= m; j ++) {
      for (int k = 0; k <= K; k ++) {
        auto add = [&](int &a, int b) {
          a += b;
          if (a < 0) a += mod;
          if (a >= mod) a -= mod;
        };
        add(dp[i + 1][j][k], dp[i][j][k]);
        add(dp[i][j + 1][k], dp[i][j][k]);
        add(dp[i + 1][j + 1][k], -dp[i][j][k]);
        if (a[i + 1] > b[j + 1]) {
          add(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
        }
      }
    }
  }
  cout << dp[n][m][K] << endl;
}