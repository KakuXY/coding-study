#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> s(n);
  for (auto &x : s) cin >> x;
  vector<int> cnt(4);
  while (m --) {
    int x;
    cin >> x;
    cnt[x - 1] ++;
  }
  vector<array<array<array<int, 41>, 41>, 41>> dp(41);
  dp[0][0][0][0] = s[0];
  for (int a = 0; a <= cnt[0]; a ++) {
    for (int b = 0; b <= cnt[1]; b ++) {
      for (int c = 0; c <= cnt[2]; c ++) {
        for (int d = 0; d <= cnt[3]; d ++) {
          int index = a + b * 2 + c * 3 + d * 4;
          auto &res = dp[a][b][c][d];
          if (a) res = max(res, dp[a - 1][b][c][d] + s[index]);
          if (b) res = max(res, dp[a][b - 1][c][d] + s[index]);
          if (c) res = max(res, dp[a][b][c - 1][d] + s[index]);
          if (d) res = max(res, dp[a][b][c][d - 1] + s[index]);
        }
      }
    }
  }
  cout << dp[ cnt[0] ][ cnt[1] ][ cnt[2] ][ cnt[3] ] << endl;
}