#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(n + 2), b(m + 2);
  for (int i = 1; i <= n; i ++) cin >> a[i];
  for (int j = 1; j <= m; j ++) cin >> b[j];
  sort(a.begin() + 1, a.begin() + 1 + n);
  sort(b.begin() + 1, b.begin() + 1 + m);
  vector<vector<array<double, 2>>> dp(n + 2, vector<array<double, 2>>(m + 2, {1e300, 1e300}));
  dp[0][0][0] = 0;
  for (int i = 0; i <= n; i ++) {
    for (int j = 0; j <= m; j ++) {
      auto checkmin = [](auto &a, auto b) { a = a < b ? a : b; };
      checkmin(dp[i + 1][j][0], dp[i][j][0] + a[i + 1] - a[i]);
      checkmin(dp[i][j + 1][1], dp[i][j][0] + hypot(a[i] - b[j + 1], d));
      checkmin(dp[i + 1][j][0], dp[i][j][1] + hypot(b[j] - a[i + 1], d));
      checkmin(dp[i][j + 1][1], dp[i][j][1] + b[j + 1] - b[j]);
    }
  }
  cout << fixed << setprecision(2);
  cout << min(dp[n][m][0], dp[n][m][1]) << endl;
}