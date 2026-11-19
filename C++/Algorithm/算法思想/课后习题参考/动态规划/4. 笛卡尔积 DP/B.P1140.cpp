#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int scores[5][5] = {
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, 0}
  };
  int n, m;
  string s, t;
  cin >> n >> s;
  cin >> m >> t;
  s = " " + s + " ";
  t = " " + t + " ";
  vector<int> index(128);
  index['A'] = 0;
  index['C'] = 1;
  index['G'] = 2;
  index['T'] = 3;
  vector<vector<int>> dp(n + 2, vector<int>(m + 2, INT_MIN / 2));
  dp[0][0] = 0;
  auto checkmax = [&](int &a, int b) {
    a = a < b ? b : a;
  };
  for (int i = 0; i <= n; i ++) {
    for (int j = 0; j <= m; j ++) {
      int si = index[ s[i + 1] ], tj = index[ t[j + 1] ];
      checkmax(dp[i][j + 1], dp[i][j] + scores[4][tj]);
      checkmax(dp[i + 1][j], dp[i][j] + scores[si][4]);
      checkmax(dp[i + 1][j + 1], dp[i][j] + scores[si][tj]);
    }
  }
  cout << dp[n][m] << endl;
}