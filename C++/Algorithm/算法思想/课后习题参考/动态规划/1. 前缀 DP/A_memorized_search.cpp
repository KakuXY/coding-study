#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;



int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<vector<int>> w(n, vector<int>(n));
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j <= i; j ++) {
      cin >> w[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(n, -1));
  auto dfs = [&](auto &self, int i, int j) {
    auto &res = dp[i][j];
    if (res != -1) return res;
    if (i == 0) return res = w[i][j];
    if (j == 0) return res = self(self, i - 1, j) + w[i][j];
    if (j == i) return res = self(self, i - 1, j - 1) + w[i][j];
    return res = max(self(self, i - 1, j - 1), self(self, i - 1, j)) + w[i][j];
  };
  int ans = 0;
  for (int j = 0; j < n; j ++) {
    ans = max(ans, dfs(dfs, n - 1, j));
  }
  cout << ans << endl;
}