#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

void solve() {
  int n, V;
  cin >> n >> V;
  vector<int> dp(V + 1);
  for (int i = 1; i <= n; i ++) {
    int lose, win, use;
    cin >> lose >> win >> use;
    for (int j = V; j >= 0; j --) {
      if (j >= use) {
        dp[j] = max(dp[j] + lose, dp[j - use] + win);
      } else {
        dp[j] = dp[j] + lose;
      }
    }
  }
  cout << dp[V] * 5ll << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  for (int cas = 1; cas <= T; cas ++) {
    solve();
  }
}