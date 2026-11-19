#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<vector<int>> maze(n, vector<int>(n));
  for (auto &row : maze) {
    for (auto &x : row) cin >> x;
  }
  int ans = 0;
  
  for (int c = 0; c <= 10; c ++) {
    vector<int> height(n, 0);

    auto calc = [&]() {
      vector<int> dp(n);
      for (int i = 0; i < n; i ++) {
        if (i == 0) dp[0] = min(1, height[0]);
        else dp[i] = min(dp[i - 1] + 1, height[i]);
      }
      ans = max(ans, *max_element(dp.begin(), dp.end()));
    };

    auto calc_row = [&](int i) {
      for (int j = 0; j < n; j ++) {
        if (maze[i][j] == c) height[j] ++;
        else height[j] = 0;
      }
      calc();
      reverse(height.begin(), height.end());
      calc();
      reverse(height.begin(), height.end());
    };

    for (int i = 0; i < n; i ++) calc_row(i);
    fill(height.begin(), height.end(), 0);
    for (int i = n - 1; i >= 0; i --) calc_row(i);
  }
  cout << ans << endl;
}