#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, h, delta;
  cin >> n >> h >> delta;
  vector<vector<int>> w(h + 2, vector<int>(n, 0));
  auto dp = w;
  for (int i = 0; i < n; i ++) {
    int ni;
    cin >> ni;
    while (ni --) {
      int j;
      cin >> j;
      w[j][i] ++;
    }
  }
  for (int i = h; i >= 1; i --) {
    for (int j = 0; j < n; j ++) {
      dp[i][j] = dp[i + 1][j] + w[i][j];
    }
    if (i + delta <= h) {
      int mx = 0;
      for (int j = 0; j < n; j ++) {
        mx = max(mx, dp[i + delta][j]);
      }
      for (int j = 0; j < n; j ++) {
        dp[i][j] = max(dp[i][j], mx + w[i][j]);
      }
    }
  }
  cout << *max_element(dp[1].begin(), dp[1].end()) << endl;
}