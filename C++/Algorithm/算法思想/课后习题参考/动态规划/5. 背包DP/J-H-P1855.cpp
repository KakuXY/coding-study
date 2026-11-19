#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

void solve() {
  int n, M, T;
  cin >> n >> M >> T;
  vector<vector<int>> dp(M + 1, vector<int>(T + 1));
  while (n --) {
    int m, t;
    cin >> m >> t;
    for (int i = M; i >= m; i --) {
      for (int j = T; j >= t; j --) {
        dp[i][j] = max(dp[i][j], dp[i - m][j - t] + 1);
      }
    }
  }
  cout << dp[M][T] << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  for (int cas = 1; cas <= T; cas ++) {
    solve();
  }
}