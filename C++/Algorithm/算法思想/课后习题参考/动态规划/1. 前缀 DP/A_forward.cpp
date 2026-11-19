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

  vector<vector<int>> dp(n, vector<int>(n, 0));
  dp[0][0] = w[0][0];
  for (int i = 0; i + 1 < n; i ++) {
    for (int j = 0; j <= i; j ++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + w[i + 1][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + w[i + 1][j + 1]);
    }
  }
  cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
}