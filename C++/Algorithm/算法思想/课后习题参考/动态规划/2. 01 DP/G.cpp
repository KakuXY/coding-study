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
  const int inf = INT_MAX / 2;
  vector<pair<int, int>> dp(m + 1, {inf, inf});
  dp[0] = {0, inf};
  while (n --) {
    int x;
    cin >> x;
    if (x > 119) continue;
    for (int i = m; i >= 1; i --) {
      pair<int, int> nxt = {dp[i - 1].first, dp[i - 1].second + x};
      if (nxt.second > 119) {
        nxt.first += 1;
        nxt.second = x;
      }
      dp[i] = min(dp[i], nxt);
    }
  }
  if (dp[m].first == inf) cout << "You can't do it." << endl;
  else cout << dp[m].first << endl;
}