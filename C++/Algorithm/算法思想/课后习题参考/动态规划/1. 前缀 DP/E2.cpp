#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string str;
  cin >> str;
  int n = str.size();
  vector<vector<int>> dp(n, vector<int>(2));
  for (int i = 0; i < n; i ++) {
    int v = str[i] - 'a' + 1;
    if (i == 0) {
      dp[i][0] = 0;
      dp[i][1] = v;
    } else {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = dp[i - 1][0] + v;
    }
  }
  cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
}