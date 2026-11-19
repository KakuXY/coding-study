#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, K;
  cin >> n >> K;
  vector<pair<int, int>> pos(n);
  for (auto &[x, y] : pos) cin >> x >> y;
  sort(pos.begin(), pos.end());
  vector<vector<int>> dp(n, vector<int>(K + 1));
  int ans = 0;
  debug(pos);
  for (int i = 0; i < n; i ++) dp[i][0] = 1;
  for (int i = 1; i < n; i ++) {
    for (int k = 0; k <= K; k ++) {
      for (int j = 0; j < i; j ++) {
        if (pos[j].second <= pos[i].second) {
          int dist = pos[i].first - pos[j].first + pos[i].second - pos[j].second;
          if (k - (dist - 1) < 0) continue;
          dp[i][k] = max(dp[i][k], dp[j][k - (dist - 1)] + dist);
          ans = max(ans, dp[i][k] + (K - k));
        }
      }
    }
  }
  debug(dp);
  cout << ans << endl;
}