#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

const int inf = INT_MAX / 2;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int cas = 1;
  int n;
  while (cin >> n && n) {
    int T;
    cin >> T;
    vector<int> dis(n);
    for (int i = 1; i < n; i ++) {
      int t;
      cin >> t;
      dis[i] = dis[i - 1] + t;
    }
    int m1, m2;
    cin >> m1;
    vector<int> a(m1);
    for (auto &x : a) cin >> x;
    cin >> m2;
    vector<int> b(m2);
    for (auto &x : b) cin >> x;
    vector<vector<int>> dp(T + 1, vector<int>(n, inf));
    dp[0][0] = 0;
    debug(dis);
    debug(a);
    debug(b);
    for (int i = 0; i < T; i ++) {
      for (int j = 0; j < n; j ++) {
        if (dp[i][j] == inf) continue;
        // dp[i][j] -> dp[?][j+1, j-1]
        for (auto x : a) {
          int arriveT = x + dis[j];
          if (arriveT < i) continue;
          int waitT = arriveT - i;
          if (j + 1 == n) continue;
          int nextT = x + dis[j + 1];
          if (nextT > T) continue;
          dp[nextT][j + 1] = min(dp[nextT][j + 1], dp[i][j] + waitT);
        }

        for (auto x : b) {
          int arriveT = x + (dis[n - 1] - dis[j]);
          if (arriveT < i) continue;
          int waitT = arriveT - i;
          if (j - 1 == -1) continue;
          int nextT = x + (dis[n - 1] - dis[j - 1]);
          if (nextT > T) continue;
          dp[nextT][j - 1] = min(dp[nextT][j - 1], dp[i][j] + waitT);
        }
      }
    }
    int ans = inf;
    for (int i = 0; i <= T; i ++) {
      if (dp[i][n - 1] == inf) continue;
      ans = min(ans, dp[i][n - 1] + T - i);
    }
    cout << "Case Number " << cas ++ << ": ";
    if (ans == inf) cout << "impossible" << endl;
    else cout << ans << endl;
  }
}