#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

constexpr int inf = INT_MAX / 2;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, s, t;
  cin >> n >> s >> t;
  using tp = tuple<int, int, int, int>;
  vector<tp> board(n);
  for (int i = 0; i < n; i ++) {
    auto &[h, l, r, id] = board[i];
    cin >> l >> r >> h;
    id = i + 1;
  }
  sort(board.begin(), board.end(), greater<tp>());
  vector<array<int, 2>> dp(n, {inf, inf});
  for (int i = 0; i < n; i ++) {
    if (get<3>(board[i]) == s) {
      dp[i][0] = 0;
      dp[i][1] = get<2>(board[i]) - get<1>(board[i]);
    }
  }
  int ans = inf;
  for (int i = 0; i < n; i ++) {
    auto [h, l, r, _] = board[i];
    for (int j = i + 1; j < n; j ++) {
      auto [hh, ll, rr, id] = board[j];
      if (ll <= l && l <= rr) {
        if (id == t) {
          ans = min(ans, dp[i][0] + h - hh);
        }
        dp[j][0] = min(dp[j][0], dp[i][0] + h - hh + l - ll);
        dp[j][1] = min(dp[j][1], dp[i][0] + h - hh + rr - l);
        break;
      }
    }
    for (int j = i + 1; j < n; j ++) {
      auto [hh, ll, rr, id] = board[j];
      if (ll <= r && r <= rr) {
        if (id == t) {
          ans = min(ans, dp[i][1] + h - hh);
        }
        dp[j][0] = min(dp[j][0], dp[i][1] + h - hh + r - ll);
        dp[j][1] = min(dp[j][1], dp[i][1] + h - hh + rr - r);
        break;
      }
    }
  }
  debug(dp);
  if (ans == inf) cout << "-1" << endl;
  else cout << ans << endl;
}